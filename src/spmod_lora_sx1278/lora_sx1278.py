from machine import I2C
from Maix import GPIO

from fpioa_manager import fm
import utime
import sensor, image, time
import lcd

# RFM98 Internal registers Address
# /********************LoRa mode***************************/
LR_RegFifo = 0x00 
#  Common settings
LR_RegOpMode = 0x01 
LR_RegFrMsb = 0x06  
LR_RegFrMid = 0x07  
LR_RegFrLsb = 0x08  
#  Tx settings
LR_RegPaConfig = 0x09 
LR_RegPaRamp = 0x0A   
LR_RegOcp = 0x0B      
#  Rx settings
LR_RegLna = 0x0C 
# LoRa registers
LR_RegFifoAddrPtr = 0x0D         
LR_RegFifoTxBaseAddr = 0x0E      
LR_RegFifoRxBaseAddr = 0x0F      
LR_RegFifoRxCurrentaddr = 0x10   
LR_RegIrqFlagsMask = 0x11        
LR_RegIrqFlags = 0x12            
LR_RegRxNbBytes = 0x13           
LR_RegRxHeaderCntValueMsb = 0x14 
LR_RegRxHeaderCntValueLsb = 0x15 
LR_RegRxPacketCntValueMsb = 0x16 
LR_RegRxPacketCntValueLsb = 0x17 
LR_RegModemStat = 0x18           
LR_RegPktSnrValue = 0x19         
LR_RegPktRssiValue = 0x1A        
LR_RegRssiValue = 0x1B           
LR_RegHopChannel = 0x1C          
LR_RegModemConfig1 = 0x1D        
LR_RegModemConfig2 = 0x1E        
LR_RegSymbTimeoutLsb = 0x1F      
LR_RegPreambleMsb = 0x20         
LR_RegPreambleLsb = 0x21         
LR_RegPayloadLength = 0x22       
LR_RegMaxPayloadLength = 0x23    
LR_RegHopPeriod = 0x24           
LR_RegFifoRxByteAddr = 0x25      
#  I/O settings
REG_LR_DIOMAPPING1 = 0x40 
REG_LR_DIOMAPPING2 = 0x41 
#  Version
REG_LR_VERSION = 0x42 
#  Additional settings
REG_LR_PLLHOP = 0x44     
REG_LR_TCXO = 0x4B       
REG_LR_PADAC = 0x4D      
REG_LR_FORMERTEMP = 0x5B 
REG_LR_AGCREF = 0x61     
REG_LR_AGCTHRESH1 = 0x62 
REG_LR_AGCTHRESH2 = 0x63 
REG_LR_AGCTHRESH3 = 0x64 

# /********************FSK/ook mode***************************/
RegFIFO = 0x00           
RegOpMode = 0x01         
RegBitRateMsb = 0x02     
RegBitRateLsb = 0x03     
RegFdevMsb = 0x04        
RegFdevLsb = 0x05        
RegFreqMsb = 0x06        
RegFreqMid = 0x07        
RegFreqLsb = 0x08        
RegPaConfig = 0x09       
RegPaRamp = 0x0a         
RegOcp = 0x0b            
RegLna = 0x0c            
RegRxConfig = 0x0d       
RegRssiConfig = 0x0e     
RegRssiCollision = 0x0f  
RegRssiThresh = 0x10     
RegRssiValue = 0x11      
RegRxBw = 0x12           
RegAfcBw = 0x13          
RegOokPeak = 0x14        
RegOokFix = 0x15         
RegOokAvg = 0x16         
RegAfcFei = 0x1a         
RegAfcMsb = 0x1b         
RegAfcLsb = 0x1c         
RegFeiMsb = 0x1d         
RegFeiLsb = 0x1e         
RegPreambleDetect = 0x1f 
RegRxTimeout1 = 0x20     
RegRxTimeout2 = 0x21     
RegRxTimeout3 = 0x22     
RegRxDelay = 0x23        
RegOsc = 0x24            
RegPreambleMsb = 0x25    
RegPreambleLsb = 0x26    
RegSyncConfig = 0x27     
RegSyncValue1 = 0x28     
RegSyncValue2 = 0x29     
RegSyncValue3 = 0x2a     
RegSyncValue4 = 0x2b     
RegSyncValue5 = 0x2c     
RegSyncValue6 = 0x2d     
RegSyncValue7 = 0x2e     
RegSyncValue8 = 0x2f     
RegPacketConfig1 = 0x30  
RegPacketConfig2 = 0x31  
RegPayloadLength = 0x32  
RegNodeAdrs = 0x33       
RegBroadcastAdrs = 0x34  
RegFifoThresh = 0x35     
RegSeqConfig1 = 0x36     
RegSeqConfig2 = 0x37     
RegTimerResol = 0x38     
RegTimer1Coef = 0x39     
RegTimer2Coef = 0x3a     
RegImageCal = 0x3b       
RegTemp = 0x3c           
RegLowBat = 0x3d         
RegIrqFlags1 = 0x3e      
RegIrqFlags2 = 0x3f      
RegDioMapping1 = 0x40    
RegDioMapping2 = 0x41    
RegVersion = 0x42        
RegPllHop = 0x44         
RegPaDac = 0x4d          
RegBitRateFrac = 0x5d    

class SX1278:
    def __init__(spi):
        self.spi = spi
    
    def begin(self, freq, power, lora_rate, lora_bw, pack_len):
        self.freq = freq
        self.power = power
        self.lora_rate = lora_rate
        self.lora_bw = lora_bw
        self.pack_len = pack_len

    def sleep(self):
        self.write(LR_RegOpMode, 0x08);
        self.status = SLEEP

    def write(self, addr, cmd):
        addr = addr | 0x80;
        self.spi.write(cs,cmd);
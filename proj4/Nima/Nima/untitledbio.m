function bio=untitledbio
bio = [];
bio(1).blkName='PCI-6024E AD';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&untitled_B.PCI6024EAD';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Signal Generator';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&untitled_B.SignalGenerator';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Discrete FIR Filter';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&untitled_B.DiscreteFIRFilter';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Async Rate Transition /Rate Transition';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&untitled_B.RateTransition';
bio(4).ndims=2;
bio(4).size=[];


function len = getlenBIO
len = 4;


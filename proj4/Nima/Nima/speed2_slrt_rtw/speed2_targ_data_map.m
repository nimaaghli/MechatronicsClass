  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (speed2_P)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% speed2_P.Counter2_InitialCount
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_P.Counter_InitialCount
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_P.Counter1_InitialCount
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 66;
      section.data(66)  = dumData; %prealloc
      
	  ;% speed2_P._Y0
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_P.PulseGenerator_Amp
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_P.PulseGenerator_Period
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_P.PulseGenerator_Duty
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% speed2_P.PulseGenerator_PhaseDelay
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% speed2_P.TmpLatchAtSampleandHold1Inport1
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% speed2_P.TmpLatchAtSampleandHold2Inport1
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% speed2_P.UniformRandomNumber_Minimum
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% speed2_P.UniformRandomNumber_Maximum
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% speed2_P.UniformRandomNumber_Seed
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% speed2_P.Gain2_Gain
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 10;
	
	  ;% speed2_P.Constant_Value
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 11;
	
	  ;% speed2_P.PCI6024EDO_P1_Size
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 12;
	
	  ;% speed2_P.PCI6024EDO_P1
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 14;
	
	  ;% speed2_P.PCI6024EDO_P2_Size
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 15;
	
	  ;% speed2_P.PCI6024EDO_P2
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 17;
	
	  ;% speed2_P.PCI6024EDO_P3_Size
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 18;
	
	  ;% speed2_P.PCI6024EDO_P3
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 20;
	
	  ;% speed2_P.PCI6024EDO_P4_Size
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 21;
	
	  ;% speed2_P.PCI6024EDO_P4
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 23;
	
	  ;% speed2_P.PCI6024EDO_P5_Size
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 24;
	
	  ;% speed2_P.PCI6024EDO_P5
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 26;
	
	  ;% speed2_P.PCI6024EDO_P6_Size
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 27;
	
	  ;% speed2_P.PCI6024EDO_P6
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 29;
	
	  ;% speed2_P.PCI6024EDO_P7_Size
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 30;
	
	  ;% speed2_P.PCI6024EDO_P7
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 32;
	
	  ;% speed2_P.Gain_Gain
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 33;
	
	  ;% speed2_P.ucounts1rev1_Value
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 34;
	
	  ;% speed2_P.rev360degree1_Value
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 35;
	
	  ;% speed2_P.converstionfactor2132_Value
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 36;
	
	  ;% speed2_P.PCI6024EDI_P1_Size
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 37;
	
	  ;% speed2_P.PCI6024EDI_P1
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 39;
	
	  ;% speed2_P.PCI6024EDI_P2_Size
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 40;
	
	  ;% speed2_P.PCI6024EDI_P2
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 42;
	
	  ;% speed2_P.PCI6024EDI_P3_Size
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 43;
	
	  ;% speed2_P.PCI6024EDI_P3
	  section.data(36).logicalSrcIdx = 38;
	  section.data(36).dtTransOffset = 45;
	
	  ;% speed2_P.PCI6024EDI_P4_Size
	  section.data(37).logicalSrcIdx = 39;
	  section.data(37).dtTransOffset = 46;
	
	  ;% speed2_P.PCI6024EDI_P4
	  section.data(38).logicalSrcIdx = 40;
	  section.data(38).dtTransOffset = 48;
	
	  ;% speed2_P.PCI6024EDI_P5_Size
	  section.data(39).logicalSrcIdx = 41;
	  section.data(39).dtTransOffset = 49;
	
	  ;% speed2_P.PCI6024EDI_P5
	  section.data(40).logicalSrcIdx = 42;
	  section.data(40).dtTransOffset = 51;
	
	  ;% speed2_P.PCI6024EDI1_P1_Size
	  section.data(41).logicalSrcIdx = 43;
	  section.data(41).dtTransOffset = 52;
	
	  ;% speed2_P.PCI6024EDI1_P1
	  section.data(42).logicalSrcIdx = 44;
	  section.data(42).dtTransOffset = 54;
	
	  ;% speed2_P.PCI6024EDI1_P2_Size
	  section.data(43).logicalSrcIdx = 45;
	  section.data(43).dtTransOffset = 55;
	
	  ;% speed2_P.PCI6024EDI1_P2
	  section.data(44).logicalSrcIdx = 46;
	  section.data(44).dtTransOffset = 57;
	
	  ;% speed2_P.PCI6024EDI1_P3_Size
	  section.data(45).logicalSrcIdx = 47;
	  section.data(45).dtTransOffset = 58;
	
	  ;% speed2_P.PCI6024EDI1_P3
	  section.data(46).logicalSrcIdx = 48;
	  section.data(46).dtTransOffset = 60;
	
	  ;% speed2_P.PCI6024EDI1_P4_Size
	  section.data(47).logicalSrcIdx = 49;
	  section.data(47).dtTransOffset = 61;
	
	  ;% speed2_P.PCI6024EDI1_P4
	  section.data(48).logicalSrcIdx = 50;
	  section.data(48).dtTransOffset = 63;
	
	  ;% speed2_P.PCI6024EDI1_P5_Size
	  section.data(49).logicalSrcIdx = 51;
	  section.data(49).dtTransOffset = 64;
	
	  ;% speed2_P.PCI6024EDI1_P5
	  section.data(50).logicalSrcIdx = 52;
	  section.data(50).dtTransOffset = 66;
	
	  ;% speed2_P.ucounts1rev_Value
	  section.data(51).logicalSrcIdx = 53;
	  section.data(51).dtTransOffset = 67;
	
	  ;% speed2_P.rev360degree_Value
	  section.data(52).logicalSrcIdx = 54;
	  section.data(52).dtTransOffset = 68;
	
	  ;% speed2_P.converstionfactor2131_Value
	  section.data(53).logicalSrcIdx = 55;
	  section.data(53).dtTransOffset = 69;
	
	  ;% speed2_P.PCI6024EAD_P1_Size
	  section.data(54).logicalSrcIdx = 56;
	  section.data(54).dtTransOffset = 70;
	
	  ;% speed2_P.PCI6024EAD_P1
	  section.data(55).logicalSrcIdx = 57;
	  section.data(55).dtTransOffset = 72;
	
	  ;% speed2_P.PCI6024EAD_P2_Size
	  section.data(56).logicalSrcIdx = 58;
	  section.data(56).dtTransOffset = 73;
	
	  ;% speed2_P.PCI6024EAD_P2
	  section.data(57).logicalSrcIdx = 59;
	  section.data(57).dtTransOffset = 75;
	
	  ;% speed2_P.PCI6024EAD_P3_Size
	  section.data(58).logicalSrcIdx = 60;
	  section.data(58).dtTransOffset = 76;
	
	  ;% speed2_P.PCI6024EAD_P3
	  section.data(59).logicalSrcIdx = 61;
	  section.data(59).dtTransOffset = 78;
	
	  ;% speed2_P.PCI6024EAD_P4_Size
	  section.data(60).logicalSrcIdx = 62;
	  section.data(60).dtTransOffset = 79;
	
	  ;% speed2_P.PCI6024EAD_P4
	  section.data(61).logicalSrcIdx = 63;
	  section.data(61).dtTransOffset = 81;
	
	  ;% speed2_P.PCI6024EAD_P5_Size
	  section.data(62).logicalSrcIdx = 64;
	  section.data(62).dtTransOffset = 82;
	
	  ;% speed2_P.PCI6024EAD_P5
	  section.data(63).logicalSrcIdx = 65;
	  section.data(63).dtTransOffset = 84;
	
	  ;% speed2_P.PCI6024EAD_P6_Size
	  section.data(64).logicalSrcIdx = 66;
	  section.data(64).dtTransOffset = 85;
	
	  ;% speed2_P.PCI6024EAD_P6
	  section.data(65).logicalSrcIdx = 67;
	  section.data(65).dtTransOffset = 87;
	
	  ;% speed2_P.Gain1_Gain
	  section.data(66).logicalSrcIdx = 68;
	  section.data(66).dtTransOffset = 88;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% speed2_P.Q_Y0
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_P.Q_Y0_i
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_P.Memory_X0
	  section.data(3).logicalSrcIdx = 71;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_P.Logic_table
	  section.data(4).logicalSrcIdx = 72;
	  section.data(4).dtTransOffset = 3;
	
	  ;% speed2_P.Memory1_X0
	  section.data(5).logicalSrcIdx = 73;
	  section.data(5).dtTransOffset = 19;
	
	  ;% speed2_P.TmpLatchAtJKFlipFlopInport1_X0
	  section.data(6).logicalSrcIdx = 74;
	  section.data(6).dtTransOffset = 20;
	
	  ;% speed2_P.TmpLatchAtJKFlipFlopInport2_X0
	  section.data(7).logicalSrcIdx = 75;
	  section.data(7).dtTransOffset = 21;
	
	  ;% speed2_P.Memory_X0_c
	  section.data(8).logicalSrcIdx = 76;
	  section.data(8).dtTransOffset = 22;
	
	  ;% speed2_P.Constant_Value_m
	  section.data(9).logicalSrcIdx = 77;
	  section.data(9).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% speed2_P.SampleandHold2._Y0
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% speed2_P.SampleandHold1._Y0
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (speed2_B)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% speed2_B.PulseGenerator
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_B.Counter2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_B.TmpLatchAtSampleandHold1Inport1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_B.TmpLatchAtSampleandHold2Inport1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% speed2_B.Subtract
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% speed2_B.UniformRandomNumber
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% speed2_B.Gain2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% speed2_B.Subtract1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% speed2_B.DataTypeConversion
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% speed2_B.Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% speed2_B.Divide2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% speed2_B.multply1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% speed2_B.Divide3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% speed2_B.PCI6024EDI
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% speed2_B.Counter
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% speed2_B.PCI6024EDI1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% speed2_B.Counter1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% speed2_B.Sum
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% speed2_B.Divide
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% speed2_B.multply
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% speed2_B.Divide1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% speed2_B.PCI6024EAD
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% speed2_B.RateTransition
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% speed2_B.Gain1
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% speed2_B.In
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% speed2_B.Memory1
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_B.TmpLatchAtJKFlipFlopInport1
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_B.TmpLatchAtJKFlipFlopInport2
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_B.Memory
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% speed2_B.Compare
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% speed2_B.Memory_c
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% speed2_B.Logic
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
	  ;% speed2_B.OutportBufferForQ
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% speed2_B.SampleandHold2.In
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% speed2_B.SampleandHold1.In
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (speed2_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% speed2_DW.TmpLatchAtSampleandHold1Inport1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_DW.TmpLatchAtSampleandHold2Inport1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_DW.UniformRandomNumber_NextOutput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_DW.PCI6024EAD_RWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% speed2_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_DW.Scope2_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_DW.ToWorkspace_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% speed2_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% speed2_DW.Counter2_Count
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_DW.Counter2_ClkEphState
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_DW.Counter2_RstEphState
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_DW.RandSeed
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% speed2_DW.Counter_Count
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% speed2_DW.Counter_ClkEphState
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% speed2_DW.Counter1_Count
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% speed2_DW.Counter1_ClkEphState
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% speed2_DW.PCI6024EDO_IWORK
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_DW.SFunction_IWORK.AcquireOK
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 3;
	
	  ;% speed2_DW.SFunction_IWORK_i.AcquireOK
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 4;
	
	  ;% speed2_DW.SFunction_IWORK_o.AcquireOK
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 5;
	
	  ;% speed2_DW.PCI6024EDI_IWORK
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 6;
	
	  ;% speed2_DW.PCI6024EDI1_IWORK
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 9;
	
	  ;% speed2_DW.PCI6024EAD_IWORK
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 12;
	
	  ;% speed2_DW.SFunction_IWORK_c.AcquireOK
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 78;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% speed2_DW.SampleandHold3_SubsysRanBC
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_DW.JKFlipFlop_SubsysRanBC
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% speed2_DW.Memory1_PreviousInput
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% speed2_DW.TmpLatchAtJKFlipFlopInport1_Pre
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% speed2_DW.TmpLatchAtJKFlipFlopInport2_Pre
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% speed2_DW.Memory_PreviousInput
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% speed2_DW.Memory_PreviousInput_j
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% speed2_DW.SampleandHold2.SampleandHold1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% speed2_DW.SampleandHold1.SampleandHold1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1330278854;
  targMap.checksum1 = 1632065287;
  targMap.checksum2 = 201435141;
  targMap.checksum3 = 626921919;


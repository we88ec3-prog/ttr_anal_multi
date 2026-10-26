
undefined4 FUN_008c8e10(int param_1,char param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  ushort *puVar3;
  byte *in_EAX;
  byte *pbVar4;
  uint *unaff_EDI;
  
  pbVar2 = (byte *)*unaff_EDI;
  puVar3 = *(ushort **)(param_1 + 0xc);
  pbVar1 = pbVar2 + 5;
  if (in_EAX < pbVar1) {
    return 6;
  }
  *puVar3 = (ushort)*pbVar2;
  puVar3[1] = (ushort)pbVar2[1];
  puVar3[2] = (short)(char)pbVar2[2];
  puVar3[3] = (short)(char)pbVar2[3];
  puVar3[4] = (ushort)pbVar2[4];
  pbVar4 = pbVar1;
  if (param_2 != '\0') {
    pbVar4 = pbVar2 + 8;
    if (in_EAX < pbVar4) {
      return 6;
    }
    puVar3[5] = (short)(char)*pbVar1;
    puVar3[6] = (short)(char)pbVar2[6];
    puVar3[7] = (ushort)pbVar2[7];
  }
  *(undefined1 *)(param_1 + 0x10) = 1;
  *unaff_EDI = (uint)pbVar4;
  return 0;
}


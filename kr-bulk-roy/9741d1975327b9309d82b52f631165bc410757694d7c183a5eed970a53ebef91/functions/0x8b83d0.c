
undefined4 FUN_008b83d0(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  if (((param_1 == (undefined4 *)0x0) || (param_2 == (byte *)0x0)) ||
     (pbVar2 = (byte *)*param_1, pbVar4 = param_2, pbVar2 == (byte *)0x0)) {
    return 0;
  }
LAB_008b83f2:
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 == *pbVar4) {
      if (bVar1 != 0) {
        bVar1 = pbVar2[1];
        bVar5 = bVar1 < pbVar4[1];
        if (bVar1 != pbVar4[1]) goto LAB_008b8412;
        pbVar2 = pbVar2 + 2;
        pbVar4 = pbVar4 + 2;
        if (bVar1 != 0) goto LAB_008b83f2;
      }
      iVar3 = 0;
    }
    else {
LAB_008b8412:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
    }
    if (iVar3 == 0) {
      return param_1[1];
    }
    pbVar2 = (byte *)param_1[2];
    param_1 = param_1 + 2;
    pbVar4 = param_2;
    if (pbVar2 == (byte *)0x0) {
      return 0;
    }
  } while( true );
}


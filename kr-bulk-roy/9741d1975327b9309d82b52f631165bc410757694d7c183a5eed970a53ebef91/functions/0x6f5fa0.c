
int FUN_006f5fa0(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  byte *in_ECX;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  if (in_ECX == (byte *)0x0) {
    in_ECX = (byte *)FUN_006f6210(param_1);
  }
  else {
    puVar2 = (undefined4 *)FUN_006f50f0();
    if ((puVar2 != &DAT_00c0bfc8) && (0 < (int)puVar2[2])) {
      in_ECX = (byte *)FUN_006f6210(param_1);
    }
  }
  pbVar3 = (byte *)*in_EAX;
  iVar6 = 0;
  do {
    pbVar5 = in_ECX;
    if (pbVar3 == (byte *)0x0) {
      FUN_006f5580(param_1,"invalid option \'%s\'",in_ECX);
      iVar6 = FUN_006f5da0(param_2);
      return iVar6;
    }
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_006f6018:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_006f601d;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_006f6018;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_006f601d:
    if (iVar4 == 0) {
      return iVar6;
    }
    pbVar3 = (byte *)in_EAX[iVar6 + 1];
    iVar6 = iVar6 + 1;
  } while( true );
}


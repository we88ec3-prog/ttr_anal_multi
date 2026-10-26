
int FUN_008d13f0(undefined4 *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  char local_10;
  
  pbVar6 = (byte *)*param_1;
  iVar5 = 0;
  bVar7 = false;
  bVar3 = false;
  if ((pbVar6 < param_2) && (param_3 - 2U < 0x23)) {
    bVar1 = *pbVar6;
    if ((bVar1 == 0x2d) || (bVar1 == 0x2b)) {
      bVar7 = bVar1 == 0x2d;
      pbVar6 = pbVar6 + 1;
      if (pbVar6 == param_2) {
        return 0;
      }
    }
    iVar4 = (int)(0x7fffffff / (longlong)param_3);
    while (((((((pbVar6 < param_2 && (bVar1 = *pbVar6, bVar1 != 0x20)) && (bVar1 != 0xd)) &&
              ((bVar1 != 10 && (bVar1 != 9)))) &&
             ((bVar1 != 0xc && ((bVar1 != 0 && (bVar1 < 0x80)))))) &&
            (cVar2 = (&DAT_00be7e60)[bVar1 & 0x7f], -1 < cVar2)) && (cVar2 < param_3))) {
      if ((iVar4 < iVar5) ||
         ((iVar5 == iVar4 && (local_10 = (char)(0x7fffffff % (longlong)param_3), local_10 < cVar2)))
         ) {
        bVar3 = true;
      }
      else {
        iVar5 = iVar5 * param_3 + (int)cVar2;
      }
      pbVar6 = pbVar6 + 1;
    }
    *param_1 = pbVar6;
    if (bVar3) {
      iVar5 = 0x7fffffff;
    }
    if (bVar7) {
      iVar5 = -iVar5;
    }
    return iVar5;
  }
  return 0;
}



void FUN_0085dd70(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int *unaff_ESI;
  uint uVar7;
  
  if (unaff_ESI != param_1) {
    uVar7 = param_1[1] - *param_1 >> 4;
    if (uVar7 == 0) {
      FUN_0085e020(unaff_ESI,&param_1,*unaff_ESI,unaff_ESI[1]);
      return;
    }
    iVar5 = *unaff_ESI;
    uVar6 = unaff_ESI[1] - iVar5 >> 4;
    if (uVar7 <= uVar6) {
      puVar4 = (undefined4 *)FUN_0085f610(param_1[1]);
      puVar1 = (undefined4 *)unaff_ESI[1];
      for (; puVar4 != puVar1; puVar4 = puVar4 + 4) {
        (**(code **)*puVar4)(0);
      }
      unaff_ESI[1] = (param_1[1] - *param_1 & 0xfffffff0U) + *unaff_ESI;
      return;
    }
    if (uVar7 <= (uint)(unaff_ESI[2] - iVar5 >> 4)) {
      FUN_0085f610(*param_1 + uVar6 * 0x10);
      iVar5 = FUN_0085fc50(param_1[1],unaff_ESI[1],param_1);
      unaff_ESI[1] = iVar5;
      return;
    }
    if (iVar5 != 0) {
      FUN_0083f510();
      FUN_0089120c(*unaff_ESI);
    }
    piVar2 = param_1;
    cVar3 = FUN_00869870();
    if (cVar3 != '\0') {
      iVar5 = FUN_0085fc50(piVar2[1],*unaff_ESI,param_1);
      unaff_ESI[1] = iVar5;
    }
  }
  return;
}


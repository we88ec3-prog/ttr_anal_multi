
void FUN_008b8050(undefined4 *param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  param_3 = param_3 << 0x10;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (int *)0x0)) {
    uVar1 = param_1[1];
    uVar2 = *param_1;
    iVar5 = FUN_008b7dc0(uVar2,param_2[1],param_3);
    iVar6 = FUN_008b7dc0(uVar1,param_2[3],param_3);
    uVar3 = param_1[3];
    uVar4 = param_1[2];
    iVar7 = FUN_008b7dc0(uVar4,*param_2,param_3);
    iVar8 = FUN_008b7dc0(uVar3,param_2[2],param_3);
    iVar9 = FUN_008b7dc0(uVar4,param_2[1],param_3);
    iVar10 = FUN_008b7dc0(uVar3,param_2[3],param_3);
    iVar11 = FUN_008b7dc0(uVar2,*param_2,param_3);
    iVar12 = FUN_008b7dc0(uVar1,param_2[2],param_3);
    *param_2 = iVar11 + iVar12;
    param_2[1] = iVar5 + iVar6;
    param_2[2] = iVar7 + iVar8;
    param_2[3] = iVar9 + iVar10;
  }
  return;
}


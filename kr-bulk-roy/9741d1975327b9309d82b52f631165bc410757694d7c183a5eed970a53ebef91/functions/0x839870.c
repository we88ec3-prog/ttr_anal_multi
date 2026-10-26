
void FUN_00839870(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  int iVar3;
  undefined1 local_8 [4];
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 0x164);
  if ((*unaff_ESI != iVar3) && (iVar3 != 0)) {
    (**(code **)(*(int *)unaff_ESI[1] + 0x114))(iVar3);
    *unaff_ESI = iVar3;
  }
  iVar3 = unaff_ESI[1];
  iVar1 = FUN_0083ff20(iVar3 + 0x144,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x16c));
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
    if (unaff_ESI[2] != iVar1) {
      FUN_00839820();
      unaff_ESI[2] = iVar1;
    }
    FUN_0083ec20();
    return;
  }
  if (DAT_00fbacc0 != DAT_00fbacc4) {
    if (unaff_ESI[2] != 0) {
      uVar2 = FUN_0083eef0(iVar3);
      FUN_00863050(uVar2,iVar3);
    }
    FUN_0083f0d0(&DAT_00fbacc0,local_8,DAT_00fbacc0,DAT_00fbacc4);
  }
  FUN_0083d3a0(unaff_ESI[1]);
  unaff_ESI[2] = 0;
  return;
}


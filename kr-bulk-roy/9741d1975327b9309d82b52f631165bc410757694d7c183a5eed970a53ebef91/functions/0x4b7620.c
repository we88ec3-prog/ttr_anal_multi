
undefined4 FUN_004b7620(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936bfc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar5 = *(undefined4 *)(param_1 + 2);
  uVar7 = (uint)*(byte *)(param_1 + 6);
  uVar3 = FUN_0048a010(uVar7,uVar5,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0041e080(uVar3,uVar7,uVar5);
  local_14 = (uint)*(ushort *)(param_1 + 8);
  iVar4 = FUN_0040f060();
  FUN_0082ef00(&local_14);
  if (local_18 == *(int *)(iVar4 + 0xc)) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = *(int **)(local_18 + 0x10);
  }
  uVar5 = (**(code **)(*piVar8 + 0x4c))();
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 0;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_8 = 0xffffffff;
  }
  uVar2 = *(undefined2 *)(param_1 + 8);
  FUN_00551b80(0xffffffff,0xffffffff);
  FUN_00551dd0(&DAT_00fdf680,uVar2,uVar5,0,0x3f800000,1);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar6 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 7);
    puVar6[1] = 0xffffffff;
    puVar6[2] = 0xffffffff;
    puVar6[3] = 0;
    puVar6[4] = 0xf42d1;
    *(undefined1 *)(puVar6 + 5) = 0;
    *puVar6 = FoxUI::FXUIEventB2::vftable;
    *(undefined1 *)(puVar6 + 6) = uVar1;
  }
  FUN_0058b1a0(0x4b,puVar6);
  ExceptionList = local_10;
  return 0;
}


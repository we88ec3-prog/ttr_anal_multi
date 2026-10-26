
undefined1 FUN_007cbee0(undefined4 param_1)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar2 = (int *)FUN_00714770();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar2 + 0x2c))();
  iVar4 = FUN_0087dc3d(uVar3);
  (**(code **)(*piVar2 + 0x34))(0,0);
  (**(code **)(*piVar2 + 0x10))(iVar4,uVar3,1);
  uVar1 = FUN_00862450(param_1,uVar3);
  if (iVar4 != 0) {
    FUN_00891d3d(iVar4);
  }
  (**(code **)(*piVar2 + 4))();
  return uVar1;
}


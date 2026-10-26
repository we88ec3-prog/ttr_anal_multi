
undefined4 FUN_007cbf70(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_00714770();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)(*piVar1 + 0x2c))();
  iVar3 = FUN_0087dc3d(uVar2);
  (**(code **)(*piVar1 + 0x34))(0,0);
  (**(code **)(*piVar1 + 0x10))(iVar3,uVar2,1);
  uVar2 = FUN_007cc000(param_1,param_2);
  if (iVar3 != 0) {
    FUN_00891d3d(iVar3);
  }
  (**(code **)(*piVar1 + 4))();
  return uVar2;
}


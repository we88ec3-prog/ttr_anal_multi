
undefined4 FUN_00737bd0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)FUN_00714770();
  if (piVar1 == (int *)0x0) {
    return 0x8876086a;
  }
  uVar2 = (**(code **)(*piVar1 + 0x38))();
  uVar3 = (**(code **)(*piVar1 + 0x2c))();
  uVar2 = D3DXCreateTextureFromFileInMemoryEx
                    (param_1,uVar2,uVar3,0xffffffff,0xffffffff,DAT_00fba824,0,0,1,0xffffffff,
                     0xffffffff,0,0,0,param_2);
  (**(code **)(*piVar1 + 4))();
  return uVar2;
}


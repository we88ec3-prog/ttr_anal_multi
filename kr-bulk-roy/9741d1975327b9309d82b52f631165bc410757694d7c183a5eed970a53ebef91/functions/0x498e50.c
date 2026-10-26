
undefined1 FUN_00498e50(void)

{
  undefined1 uVar1;
  undefined4 *in_EAX;
  int *piVar2;
  undefined4 uVar3;
  
  if (0xf < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  piVar2 = (int *)FUN_00714770(in_EAX,&DAT_00bed1e0);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar2 + 0x38))();
  uVar3 = (**(code **)(*piVar2 + 0x2c))();
  uVar1 = FUN_00499340(uVar3);
  (**(code **)(*piVar2 + 4))();
  return uVar1;
}


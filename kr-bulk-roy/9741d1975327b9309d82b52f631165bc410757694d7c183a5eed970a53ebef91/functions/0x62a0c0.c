
void FUN_0062a0c0(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xb;
  FUN_0082ef00(&local_8);
  if (local_c == in_ECX[0x14]) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_c + 0x10);
  }
  piVar1 = in_ECX + 0x3b;
  in_ECX[0x20] = iVar2;
  FUN_0062dd00();
  if (*(int *)(*piVar1 + 0xcc) != 0) {
    FUN_006438f0(*(int *)(*piVar1 + 0xcc));
  }
  (**(code **)(*in_ECX + 0x19c))();
  FUN_00749920(*piVar1);
  (**(code **)(*(int *)*piVar1 + 200))();
  return;
}


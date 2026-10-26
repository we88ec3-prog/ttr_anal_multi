
void FUN_0061f890(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xb;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(in_ECX + 0x50)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar2;
  FUN_006c09c0(0x2b5c);
  FUN_006c09c0(0x2bc0);
  FUN_006c09c0(0x2f44);
  FUN_006c09c0(0x2fa8);
  FUN_00625780();
  FUN_006c09c0(0x332c);
  FUN_006c09c0(0x3390);
  FUN_006c09c0(0x3714);
  FUN_006c09c0(0x3778);
  FUN_006c09c0(0x3afc);
  FUN_006c09c0(0x3b60);
  FUN_00625870();
  FUN_00625960();
  *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0xd8) = 1;
  piVar1 = *(int **)(in_ECX + 0x11c);
  piVar1[0x2e] = 0x28;
  if (0x28 < piVar1[0x31]) {
    piVar1[0x31] = 0x28;
    (**(code **)(*piVar1 + 0x128))();
    (**(code **)(*piVar1 + 200))();
  }
  return;
}



void FUN_00622790(void)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  int local_c;
  int local_8;
  
  local_8 = 0xb;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(in_ECX + 0x50)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar3;
  FUN_00625a80(0x4e84);
  FUN_0043c570(0x4ee8);
  FUN_00625a80(0x526c);
  FUN_00625a80(0x5654);
  FUN_00625a80(0x5a3c);
  FUN_00625a80(0x5e24);
  FUN_00625a80(0x620c);
  FUN_0043c570(0x52d0);
  FUN_0043c570(0x56b8);
  FUN_0043c570(0x5aa0);
  FUN_0043c570(0x5e88);
  FUN_0043c570(0x6270);
  FUN_00625b70();
  piVar4 = (int *)(in_ECX + 0xf8);
  local_8 = 5;
  do {
    *(undefined4 *)(*piVar4 + 0xd8) = 10;
    piVar1 = (int *)*piVar4;
    piVar1[0x2e] = 100;
    if (100 < piVar1[0x31]) {
      pcVar2 = *(code **)(*piVar1 + 0x128);
      piVar1[0x31] = 100;
      (*pcVar2)();
      (**(code **)(*piVar1 + 200))();
    }
    piVar4 = piVar4 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}


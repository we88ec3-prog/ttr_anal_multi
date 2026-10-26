
int FUN_00879db0(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_00891268(0x88);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00879ae0();
  }
  pcVar1 = *(code **)(*(int *)(iVar2 + 0x10) + 4);
  *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 4);
  (*pcVar1)(in_ECX + 0x10);
  (**(code **)(*(int *)(iVar2 + 0x4c) + 4))(in_ECX + 0x4c);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(in_ECX + 0xc);
  return iVar2;
}


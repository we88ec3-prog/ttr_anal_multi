
void FUN_006cabd0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int local_8;
  
  FUN_00755e50();
  FUN_0043c570(14000);
  FUN_0046b6f0(0x12c0);
  FUN_0043c570(0x2b5c);
  piVar2 = (int *)(in_ECX + 0x108);
  FUN_0046b6f0(0x2b66);
  FUN_0043c570(0x1004);
  FUN_0046b6f0(0x1068);
  FUN_0043c570(0x10cc);
  FUN_0046b6f0(0x1130);
  FUN_0043c570(0x1194);
  FUN_0046b6f0(0x11f8);
  local_8 = 4;
  do {
    iVar1 = *piVar2;
    FUN_007444b0(0xbf6b);
    piVar2 = piVar2 + 1;
    local_8 = local_8 + -1;
    *(undefined1 *)(iVar1 + 0xa4) = 1;
  } while (local_8 != 0);
  FUN_0043c570(0x640);
  FUN_0043c570(0x708);
  FUN_0043c570(0x898);
  FUN_0043c570(0x8fc);
  FUN_0043c570(0x9c4);
  FUN_0043c570(0x960);
  FUN_0043c570(0xaf0);
  FUN_0043c570(0xa8c);
  FUN_0043c570(0xc1c);
  FUN_0043c570(3000);
  FUN_0043c570(0xd48);
  FUN_0043c570(0xce4);
  FUN_006ba750();
  FUN_00615fc0(6000);
  (**(code **)(**(int **)(in_ECX + 0x148) + 0x198))(0x1771);
  FUN_00615fc0(0x17d4);
  (**(code **)(**(int **)(in_ECX + 0x14c) + 0x198))(0x17d5);
  FUN_00615fc0(0x1838);
  (**(code **)(**(int **)(in_ECX + 0x150) + 0x198))(0x1839);
  return;
}


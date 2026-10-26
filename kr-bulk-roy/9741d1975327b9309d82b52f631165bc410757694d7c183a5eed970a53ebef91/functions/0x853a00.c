
void FUN_00853a00(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (in_ECX != 0) {
    puVar2 = (undefined4 *)(param_1 + 8);
    do {
      if (puVar2 != (undefined4 *)0x8) {
        puVar2[-1] = 0;
        puVar2[-2] = 0;
        puVar2[1] = 0;
        *puVar2 = 0;
        puVar2[3] = 0;
        puVar2[2] = 0;
        puVar2[5] = 0;
        puVar2[4] = 0;
        puVar2[6] = 0;
      }
      in_ECX = in_ECX + -1;
      puVar2 = puVar2 + 9;
    } while (in_ECX != 0);
  }
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


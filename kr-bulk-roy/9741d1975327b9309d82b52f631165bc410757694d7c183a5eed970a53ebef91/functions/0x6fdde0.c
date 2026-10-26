
void FUN_006fdde0(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(in_ECX + 0x44);
  if ((pcVar1 != (code *)0x0) && (*(char *)(in_ECX + 0x39) != '\0')) {
    iVar2 = *(int *)(in_ECX + 0x20);
    iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + 8);
    iVar4 = *(int *)(in_ECX + 8);
    if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) < 0x141) {
      FUN_006fdcb0();
    }
    *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 8) + 0x140;
    *(undefined1 *)(in_ECX + 0x39) = 0;
    (*pcVar1)();
    *(undefined1 *)(in_ECX + 0x39) = 1;
    *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x20) + (iVar3 - iVar2);
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 0x20) + (iVar4 - iVar2);
  }
  __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
  return;
}


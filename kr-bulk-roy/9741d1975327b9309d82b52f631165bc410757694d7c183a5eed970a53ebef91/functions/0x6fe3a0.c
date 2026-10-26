
void FUN_006fe3a0(void)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_006fdde0(0xffffffff);
  if (*(char *)(**(int **)(*(int *)(in_ECX + 0x14) + 4) + 6) == '\0') {
    bVar1 = *(byte *)(in_ECX + 0x38);
    while (((bVar1 & 2) != 0 &&
           (iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + 0x14),
           *(int *)(*(int *)(in_ECX + 0x14) + 0x14) = iVar2 + -1, iVar2 != 0))) {
      pcVar3 = *(code **)(in_ECX + 0x44);
      if ((pcVar3 != (code *)0x0) && (*(char *)(in_ECX + 0x39) != '\0')) {
        iVar2 = *(int *)(in_ECX + 8);
        iVar4 = *(int *)(in_ECX + 0x20);
        iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + 8);
        if (*(int *)(in_ECX + 0x1c) - iVar2 < 0x141) {
          FUN_006fdcb0();
        }
        *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 8) + 0x140;
        *(undefined1 *)(in_ECX + 0x39) = 0;
        (*pcVar3)();
        *(undefined1 *)(in_ECX + 0x39) = 1;
        *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x20) + (iVar5 - iVar4);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 0x20) + (iVar2 - iVar4);
      }
      bVar1 = *(byte *)(in_ECX + 0x38);
    }
  }
  __security_check_cookie(uVar6 ^ (uint)&stack0xfffffffc);
  return;
}


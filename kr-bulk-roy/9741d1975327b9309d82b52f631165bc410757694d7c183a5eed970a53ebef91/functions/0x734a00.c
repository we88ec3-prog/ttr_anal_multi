
void FUN_00734a00(void)

{
  int in_EAX;
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar2 = 0;
  if (*(int *)(in_EAX + 0xc) != 0) {
    puVar4 = (undefined4 *)(in_EAX + 0x18);
    iVar3 = in_EAX + 0x118;
    do {
      uVar1 = 0;
      if (*(int *)(in_EAX + 8) != 0) {
        do {
          *(char *)(iVar3 + uVar1) = *(char *)(in_EAX + 8) - (char)uVar1;
          uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint *)(in_EAX + 8));
      }
      *puVar4 = *(undefined4 *)(in_EAX + 8);
      uVar2 = uVar2 + 1;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 0x20;
    } while (uVar2 < *(uint *)(in_EAX + 0xc));
  }
  return;
}



void FUN_008fd6d0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint uVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(char *)(in_ECX + 0x1c) != '\0') {
    iVar1 = FUN_006dfc40();
    iVar1 = (*(int *)(iVar1 + 0x18) + -0x235) / 2;
    iVar2 = FUN_006dfc40();
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x20))
              (iVar1,(*(int *)(iVar2 + 0x1c) + -0x252) / 2,0,0xffffffff);
    uVar4 = 0;
    if (*(int *)(in_ECX + 0x50) != 0) {
      do {
        puVar3 = (undefined4 *)FUN_00572140();
        FUN_008fd480(*puVar3);
        FUN_008fd110();
        uVar4 = uVar4 + 1;
        iVar1 = unaff_EDI;
      } while (uVar4 < *(uint *)(in_ECX + 0x50));
    }
    if (*(char *)(in_ECX + 0x2e) != '\0') {
      (**(code **)(**(int **)(in_ECX + 0x28) + 0x20))
                ((int)(float)(iVar1 + 0xd0),(int)(float)(unaff_ESI + 0x9f),in_ECX + 0x34,
                 *(undefined4 *)(in_ECX + 0x30));
    }
    if (-1 < *(int *)(in_ECX + 100)) {
      FUN_00572140();
      FUN_008fd110();
    }
  }
  return;
}


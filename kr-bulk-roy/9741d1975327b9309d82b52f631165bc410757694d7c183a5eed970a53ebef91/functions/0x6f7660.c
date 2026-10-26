
void FUN_006f7660(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_EAX;
  char *pcVar3;
  undefined4 uVar4;
  undefined **local_8;
  
  local_8 = &PTR_FUN_00c0c0dc;
  do {
    FUN_006f55b0(*local_8,0);
    pcVar3 = local_8[-1];
    if (pcVar3 == (char *)0x0) {
      *(undefined4 *)(*(int *)(in_EAX + 8) + 8) = 0;
    }
    else {
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      puVar2 = *(undefined4 **)(in_EAX + 8);
      uVar4 = FUN_006fec70();
      *puVar2 = uVar4;
      puVar2[2] = 4;
    }
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
    FUN_006fe550();
    local_8 = local_8 + 2;
  } while (*local_8 != (undefined *)0x0);
  return;
}


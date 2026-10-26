
void FUN_0074d7e0(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  
  puVar5 = param_1 + 0x40;
  puVar6 = param_1;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar5 = param_1 + 0x40;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  pcVar4 = (char *)(param_1 + 0x40);
  iVar3 = 0x100;
  puVar2 = param_1 + 0x180;
  do {
    cVar1 = pcVar4[-0x100];
    if (cVar1 == '\0') {
LAB_0074d87b:
      if (*pcVar4 == '\0') {
LAB_0074d888:
        puVar2[-0x100] = 0;
      }
      else {
        puVar2[-0x100] = 1;
      }
      *puVar2 = 0;
    }
    else {
      if (*pcVar4 == '\0') {
        if (cVar1 == '\0') goto LAB_0074d87b;
        if (*pcVar4 == '\0') {
          puVar2[-0x100] = 5;
          *puVar2 = (puVar2[0x100] != 2) - 1 & 4;
          goto LAB_0074d898;
        }
        if (cVar1 == '\0') goto LAB_0074d87b;
        goto LAB_0074d888;
      }
      *puVar2 = (-(uint)(puVar2[0x100] != 1) & 0xfffffffd) + 3;
      puVar2[-0x100] = 2;
    }
LAB_0074d898:
    puVar2 = puVar2 + 1;
    pcVar4 = pcVar4 + 1;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      puVar5 = param_1 + 0x80;
      puVar6 = param_1 + 0x280;
      for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2 = param_1 + 0x180;
      puVar7 = param_1 + 0x380;
      for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar7 = puVar7 + 1;
      }
      return;
    }
  } while( true );
}


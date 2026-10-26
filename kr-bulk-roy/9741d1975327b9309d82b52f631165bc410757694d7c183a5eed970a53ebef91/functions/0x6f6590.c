
void FUN_006f6590(char *param_1,int *param_2)

{
  char cVar1;
  int in_EAX;
  int *piVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  if (param_1 != (char *)0x0) {
    iVar6 = 0;
    iVar5 = *param_2;
    piVar2 = param_2;
    while (iVar5 != 0) {
      piVar2 = piVar2 + 2;
      iVar6 = iVar6 + 1;
      iVar5 = *piVar2;
    }
    FUN_006f68a0("_LOADED",1);
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_006fec70();
    FUN_006fb850();
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
    puVar4 = (undefined4 *)(*(int *)(in_EAX + 8) + -0x10);
    if ((puVar4 == &DAT_00c0bfc8) || (*(int *)(*(int *)(in_EAX + 8) + -8) != 5)) {
      *(undefined4 **)(in_EAX + 8) = puVar4;
      iVar5 = FUN_006f68a0(param_1,iVar6);
      if (iVar5 != 0) {
        FUN_006f5f30();
      }
      puVar4 = *(undefined4 **)(in_EAX + 8);
      *puVar4 = puVar4[-4];
      puVar4[1] = puVar4[-3];
      puVar4[2] = puVar4[-2];
      *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
      FUN_006f5790();
    }
    puVar7 = *(undefined4 **)(in_EAX + 8);
    puVar4 = puVar7 + -4;
    if (puVar4 < puVar7) {
      puVar7 = puVar7 + -8;
      do {
        *puVar7 = *puVar4;
        puVar7[1] = puVar4[1];
        puVar7[2] = puVar7[6];
        puVar4 = puVar4 + 4;
        puVar7 = puVar7 + 4;
      } while (puVar4 < *(undefined4 **)(in_EAX + 8));
    }
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
    FUN_006f52b0();
  }
  iVar5 = *param_2;
  while (iVar5 != 0) {
    FUN_006f55b0(param_2[1],0);
    pcVar3 = (char *)*param_2;
    FUN_006f50f0();
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_006fec70();
    FUN_006fb9a0();
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
    param_2 = param_2 + 2;
    iVar5 = *param_2;
  }
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 8);
  return;
}


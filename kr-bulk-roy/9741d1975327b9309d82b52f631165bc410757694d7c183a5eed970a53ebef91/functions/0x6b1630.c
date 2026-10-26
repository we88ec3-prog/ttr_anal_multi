
void FUN_006b1630(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00755e50();
  FUN_006b2760();
  FUN_006b2850();
  FUN_006b2940();
  FUN_00615fc0(40000);
  FUN_00615fc0(41000);
  iVar2 = 0x5654;
  do {
    FUN_006c09c0(iVar2);
    iVar2 = iVar2 + 100;
  } while (iVar2 < 0x57e4);
  iVar2 = 31000;
  puVar3 = (undefined4 *)(in_ECX + 0x100);
  do {
    FUN_00615fc0(iVar2);
    (**(code **)(*(int *)*puVar3 + 0x198))(iVar2 + 1);
    iVar2 = iVar2 + 1000;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 38000);
  iVar2 = *(int *)(in_ECX + 0xf8);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *(int *)(in_ECX + 0xf8);
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar1 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar1 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}


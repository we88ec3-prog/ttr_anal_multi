
void FUN_008ba7e0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_EDX;
  int iVar5;
  undefined8 uVar6;
  
  puVar1 = *(undefined4 **)(in_EDX + 4);
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = *puVar1;
    uVar6 = FUN_008ba070(puVar1 + 0x25);
    iVar5 = (int)((ulonglong)uVar6 >> 0x20);
    iVar4 = (int)uVar6;
    if (iVar4 != 0) {
      iVar3 = *(int *)(iVar5 + 0xc);
      if ((*(int *)(iVar3 + 0x24) == 0x6f75746c) && (iVar5 = *(int *)(iVar5 + 0x34), iVar5 != 0)) {
        (**(code **)(*(int *)(iVar3 + 0x38) + 0x14))(iVar5);
      }
      FUN_008ba0c0(puVar1 + 0x25,iVar4);
      FUN_008b9f80(uVar2,iVar4);
      FUN_008b8f10();
    }
  }
  return;
}


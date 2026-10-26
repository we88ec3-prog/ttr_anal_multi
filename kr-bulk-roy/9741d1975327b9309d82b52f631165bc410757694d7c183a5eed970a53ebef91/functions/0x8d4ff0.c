
void FUN_008d4ff0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_8;
  
  iVar2 = param_1;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 100);
    FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 300));
    *(undefined4 *)(param_1 + 300) = 0;
    FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x124));
    *(undefined4 *)(param_1 + 0x124) = 0;
    if (*(int *)(param_1 + 0x11c) != 0) {
      local_8 = 0;
      if (0 < *(int *)(param_1 + 0x118)) {
        param_1 = 0;
        do {
          puVar3 = (undefined4 *)(*(int *)(iVar2 + 0x11c) + param_1);
          if (puVar3 != (undefined4 *)0x0) {
            FUN_008b9f80(uVar1,*puVar3);
            *puVar3 = 0;
            if (*(char *)(puVar3 + 1) != '\0') {
              FUN_008b9f80(uVar1,puVar3[2]);
              puVar3[2] = 0;
            }
          }
          param_1 = param_1 + 0xc;
          local_8 = local_8 + 1;
        } while (local_8 < *(int *)(iVar2 + 0x118));
      }
      FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0x11c));
      *(undefined4 *)(iVar2 + 0x11c) = 0;
    }
    FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0xc0));
    *(undefined4 *)(iVar2 + 0xc0) = 0;
    FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0x14));
    *(undefined4 *)(iVar2 + 0x14) = 0;
    FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0x18));
    *(undefined4 *)(iVar2 + 0x18) = 0;
    FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0x20));
    *(undefined4 *)(iVar2 + 0x20) = 0;
    FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0xb0));
    *(undefined4 *)(iVar2 + 0xb0) = 0;
    FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0xb4));
    *(undefined4 *)(iVar2 + 0xb4) = 0;
    if (*(int *)(iVar2 + 0x68) == iVar2 + 0x84) {
      FUN_008b97c0(iVar2 + 0x84);
      *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(iVar2 + 0xac);
    }
  }
  return;
}


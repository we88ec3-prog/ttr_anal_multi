
void FUN_006faef0(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_8;
  
  piVar2 = *(int **)(param_1 + 0x10);
  *(undefined1 *)(piVar2 + 5) = 0x43;
  FUN_006fab50(param_1,piVar2 + 7,0xfffffffd);
  local_8 = 0;
  if (0 < piVar2[2]) {
    do {
      iVar3 = *(int *)(param_1 + 0x10);
      puVar4 = *(undefined4 **)(*piVar2 + local_8 * 4);
      puVar6 = (undefined4 *)(*piVar2 + local_8 * 4);
      bVar1 = *(byte *)(iVar3 + 0x14);
      iVar5 = -3;
      while ((puVar4 != (undefined4 *)0x0 && (iVar5 != 0))) {
        if (*(char *)(puVar4 + 1) == '\b') {
          FUN_006fab50(param_1,puVar4 + 0x1a,0xfffffffd);
        }
        if ((byte)((bVar1 ^ 3) & (*(byte *)((int)puVar4 + 5) ^ 3)) == 0) {
          *puVar6 = *puVar4;
          if (puVar4 == *(undefined4 **)(iVar3 + 0x1c)) {
            *(undefined4 *)(iVar3 + 0x1c) = *puVar4;
          }
          FUN_006faab0();
        }
        else {
          *(byte *)((int)puVar4 + 5) =
               *(byte *)(iVar3 + 0x14) & 3 | *(byte *)((int)puVar4 + 5) & 0xf8;
          puVar6 = puVar4;
        }
        puVar4 = (undefined4 *)*puVar6;
        iVar5 = iVar5 + -1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < piVar2[2]);
  }
  return;
}


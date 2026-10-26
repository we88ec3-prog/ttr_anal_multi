
/* WARNING: Removing unreachable block (ram,0x00718f6d) */
/* WARNING: Removing unreachable block (ram,0x00718f70) */

void FUN_00718ee0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)**(int **)(param_1 + 8);
  if (piVar3 != *(int **)(param_1 + 8)) {
    do {
      puVar1 = (undefined4 *)piVar3[9];
      if (puVar1 != (undefined4 *)0x0) {
        if (0xf < (uint)puVar1[0xc]) {
          FUN_0089120c(puVar1[7]);
        }
        puVar1[0xc] = 0xf;
        puVar1[0xb] = 0;
        *(undefined1 *)(puVar1 + 7) = 0;
        if (0xf < (uint)puVar1[5]) {
          FUN_0089120c(*puVar1);
        }
        puVar1[5] = 0xf;
        puVar1[4] = 0;
        *(undefined1 *)puVar1 = 0;
        FUN_0089120c(puVar1);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 8));
  }
  iVar2 = param_1;
  puVar1 = (undefined4 *)(param_1 + 8);
  FUN_00552640(puVar1);
  param_1 = *puVar1;
  if (*(int *)(iVar2 + 0x14) != *(int *)(iVar2 + 0x18)) {
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x14);
  }
  FUN_007dcc90(*(undefined4 *)(iVar2 + 0x14),&param_1);
  *(undefined4 *)(iVar2 + 0x24) = 7;
  *(undefined4 *)(iVar2 + 0x28) = 8;
  return;
}


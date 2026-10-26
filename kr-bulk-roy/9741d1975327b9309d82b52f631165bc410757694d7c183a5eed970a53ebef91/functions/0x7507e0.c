
void FUN_007507e0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  
  if (*(int *)(in_ECX + 0x13c4) != 0) {
    puVar1 = *(undefined4 **)(in_ECX + 0x142c);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      iVar3 = puVar2[2];
      if ((((*(int *)(iVar3 + 0xc) != 0) && (piVar4 = *(int **)(iVar3 + 0xc), piVar4 != (int *)0x0))
          && ((**(code **)(*piVar4 + 0x15c))(iVar3), (*(byte *)(piVar4 + 10) & 1) != 0)) &&
         (piVar4[0x18] != 0)) {
        FUN_007506f0();
      }
    }
    puVar1 = *(undefined4 **)(in_ECX + 0x1438);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      iVar3 = puVar2[2];
      if (*(int *)(iVar3 + 0xc) != 0) {
        if (*(uint *)(iVar3 + 0x2c) < 8) {
          iVar5 = iVar3 + 0x18;
        }
        else {
          iVar5 = *(int *)(iVar3 + 0x18);
        }
        (**(code **)(**(int **)(in_ECX + 0x13c4) + 0x188))
                  (iVar5,*(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0xc));
      }
    }
    (**(code **)(**(int **)(in_ECX + 0x13c4) + 0x184))();
  }
  FUN_00753830();
  FUN_00753830();
  return;
}


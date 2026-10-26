
int * FUN_00545e20(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  uint local_10;
  
  iVar7 = 0;
  piVar3 = in_ECX;
  while( true ) {
    piVar3 = piVar3 + 3;
    piVar5 = (int *)*piVar3;
    if ((piVar5 != (int *)0x0) && ((short)piVar5[1] == *(short *)(param_1 + 2))) break;
    iVar7 = iVar7 + 1;
    if (2 < iVar7) {
      return piVar5;
    }
  }
  if (iVar7 != -1) {
    if (*(int *)(param_1 + 4) != 0) {
      piVar3 = (int *)FUN_00597b70();
      return piVar3;
    }
    if (param_2 < (int *)0x8) {
      local_10 = 0;
      piVar5 = param_2;
    }
    else {
      piVar5 = (int *)((int)(param_2 + -2) * -0x55555555);
      local_10 = (uint)(param_2 + -2) / 6;
    }
    if (local_10 != 0) {
      puVar6 = (ushort *)(param_1 + 8);
      do {
        uVar1 = *puVar6;
        iVar2 = *(int *)(puVar6 + 1);
        iVar8 = in_ECX[iVar7 * 3 + 4] + 4;
        iVar4 = FUN_0054f4e0(iVar8);
        *(uint *)(iVar4 + 0xc) = (uint)uVar1;
        piVar3 = (int *)FUN_0054f4e0(iVar8);
        *piVar3 = iVar2 / 0x21;
        iVar4 = FUN_0054f4e0(iVar8);
        *(int *)(iVar4 + 4) = iVar2 / 0x21;
        piVar5 = (int *)FUN_0054f4e0(iVar8);
        if (*piVar5 != 0) {
          piVar5 = (int *)FUN_0054f4e0(iVar8);
          *(undefined1 *)(piVar5 + 2) = 1;
        }
        puVar6 = puVar6 + 3;
        local_10 = local_10 - 1;
      } while (local_10 != 0);
    }
  }
  return piVar5;
}


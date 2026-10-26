
void FUN_00683d30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined2 *puVar5;
  int in_ECX;
  int *piVar6;
  int iVar7;
  uint uStack_18;
  int *local_10;
  undefined2 local_c;
  
  FUN_007459c0();
  iVar7 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00683d75;
    iVar7 = FUN_00745c20();
  }
  if (((iVar7 != 0) && (*(int *)(iVar7 + 0x60) != 0)) && ((*(uint *)(iVar7 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar7);
  }
LAB_00683d75:
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  *(undefined4 *)(in_ECX + 0x144) = 0xffffffff;
  puVar5 = (undefined2 *)FUN_004fb960(*(undefined4 *)(in_ECX + 0xf4));
  if (puVar5 != (undefined2 *)0x0) {
    if (*(int *)(puVar5 + 4) - 5U < 3) {
      FUN_00414680();
      FUN_004a36e0(*(undefined4 *)(in_ECX + 0xf8));
    }
    else {
      local_c = *puVar5;
      local_10 = (int *)0x2001c;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_10,6);
      }
    }
    iVar7 = 0;
    do {
      FUN_0040aa10(*(undefined4 *)(in_ECX + 0x100));
      (**(code **)(**(int **)(*(int *)(in_ECX + 0x11c) + iVar7 * 4) + 0x94))(0);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 9);
    *(undefined4 *)(in_ECX + 0x140) = *(undefined4 *)(puVar5 + 4);
    local_10 = (int *)FUN_004fc740(in_ECX + 300);
    iVar7 = *local_10;
    if (iVar7 != local_10[1]) {
      uStack_18 = 0;
      if (local_10[1] - iVar7 >> 2 != 0) {
        do {
          iVar7 = *(int *)(iVar7 + uStack_18 * 4);
          cVar4 = FUN_00682a50(*(undefined4 *)(in_ECX + 0xf4),*(undefined4 *)(in_ECX + 0xf8),iVar7);
          if (cVar4 != '\0') {
            FUN_00681e10(*(undefined4 *)(in_ECX + 0xf4),*(undefined4 *)(in_ECX + 0xf8),
                         *(undefined4 *)(puVar5 + 4),
                         (byte)(*(uint *)(*(int *)(in_ECX + 0x108) + 0x28) >> 9) & 1);
            if (*(int *)(in_ECX + 0x144) < 0) {
              *(int *)(in_ECX + 0x144) = iVar7;
            }
            (**(code **)(**(int **)(iVar7 * 4 + *(int *)(in_ECX + 0x11c)) + 0x94))(1);
            iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 0xd8);
            if (iVar1 != 0) {
              FUN_0040acb0(iVar1,iVar7,*(undefined4 *)(*(int *)(in_ECX + 0x10c) + iVar7 * 4));
            }
          }
          iVar7 = *local_10;
          uStack_18 = uStack_18 + 1;
        } while (uStack_18 < (uint)(local_10[1] - iVar7 >> 2));
      }
      piVar6 = *(int **)(in_ECX + 0x100);
      puVar2 = (undefined4 *)piVar6[0x19];
      local_10 = piVar6;
      for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
        iVar7 = puVar3[2];
        if ((*(int *)(iVar7 + 0x60) != 0) && ((*(int **)(iVar7 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar7 + 0x1c) + 0x30))(iVar7);
          piVar6 = local_10;
        }
      }
      (**(code **)(*piVar6 + 0x128))();
      FUN_0040b5b0(*(undefined4 *)(in_ECX + 0x144));
      (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
    }
  }
  return;
}


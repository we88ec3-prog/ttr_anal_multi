
void FUN_00635f10(undefined4 *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined **local_1c [3];
  char *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  FUN_007b6d70();
  iVar8 = DAT_00fe1bd0;
  while( true ) {
    if (param_1 == (undefined4 *)0x0) {
      return;
    }
    puVar7 = (undefined4 *)(*(undefined4 **)(iVar8 + 0x1c))[1];
    cVar2 = *(char *)((int)puVar7 + 0x71);
    puVar3 = *(undefined4 **)(iVar8 + 0x1c);
    while (cVar2 == '\0') {
      if ((int)puVar7[3] < (int)param_1) {
        puVar4 = (undefined4 *)puVar7[2];
        puVar7 = puVar3;
      }
      else {
        puVar4 = (undefined4 *)*puVar7;
      }
      puVar3 = puVar7;
      puVar7 = puVar4;
      cVar2 = *(char *)((int)puVar4 + 0x71);
    }
    if ((puVar3 == *(undefined4 **)(iVar8 + 0x1c)) || ((int)param_1 < (int)puVar3[3])) {
      local_c = *(undefined4 **)(iVar8 + 0x1c);
      ppuVar5 = &local_c;
    }
    else {
      ppuVar5 = &param_1;
    }
    puVar7 = *ppuVar5;
    if (puVar7 == *(undefined4 **)(iVar8 + 0x1c)) break;
    local_8 = puVar7 + 4;
    if (puVar7 + 4 == (undefined4 *)0x0) {
      return;
    }
    param_1 = (undefined4 *)puVar7[0xc];
    if (((*(int *)(in_EAX + 0xa8) + *(int *)(in_EAX + 0xac) & 3U) == 0) &&
       (*(uint *)(in_EAX + 0xa4) <= *(int *)(in_EAX + 0xac) + 4U >> 2)) {
      FUN_00636f70(in_EAX + 0x9c);
      iVar8 = DAT_00fe1bd0;
    }
    uVar9 = *(int *)(in_EAX + 0xa8) + *(int *)(in_EAX + 0xac);
    uVar10 = uVar9 >> 2;
    if (*(uint *)(in_EAX + 0xa4) <= uVar10) {
      uVar10 = uVar10 - *(uint *)(in_EAX + 0xa4);
    }
    if (*(int *)(*(int *)(in_EAX + 0xa0) + uVar10 * 4) == 0) {
      iVar6 = FUN_00891268(0x10);
      iVar8 = DAT_00fe1bd0;
      if (iVar6 == 0) {
        local_10 = (char *)0x0;
        std::exception::exception((exception *)local_1c,&local_10);
        local_1c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_1c,&DAT_00c857a8);
      }
      *(int *)(*(int *)(in_EAX + 0xa0) + uVar10 * 4) = iVar6;
    }
    piVar1 = (int *)(*(int *)(*(int *)(in_EAX + 0xa0) + uVar10 * 4) + (uVar9 & 3) * 4);
    if (piVar1 != (int *)0x0) {
      *piVar1 = (int)local_8;
    }
    *(int *)(in_EAX + 0xac) = *(int *)(in_EAX + 0xac) + 1;
  }
  return;
}


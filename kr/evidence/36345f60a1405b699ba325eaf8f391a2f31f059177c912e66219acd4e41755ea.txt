
void FUN_00545040(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  undefined4 uVar5;
  int *in_ECX;
  int *piVar6;
  ushort *puVar7;
  undefined **local_2c [3];
  int *local_20;
  char *local_1c;
  uint local_18;
  ushort *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009083ab;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = 0;
  piVar6 = in_ECX;
  do {
    piVar6 = piVar6 + 3;
    if (*piVar6 == 0) {
      local_20 = in_ECX + iVar3 * 3;
      ExceptionList = &local_10;
      in_ECX[1] = 1;
      local_20[3] = param_1;
      uVar1 = *(ushort *)(param_1 + 4);
      local_14 = (ushort *)(uint)uVar1;
      FUN_0082ef00(&local_14);
      if (local_1c == (char *)in_ECX[0x13]) {
        puVar4 = (ushort *)FUN_00891268(0x14);
        local_8 = 0;
        puVar7 = (ushort *)0x0;
        if (puVar4 != (ushort *)0x0) {
          puVar4[0] = 0;
          puVar4[1] = 0;
          puVar4[6] = 0;
          puVar4[7] = 0;
          local_14 = puVar4;
          iVar3 = FUN_00891268(0x24);
          if (iVar3 == 0) {
            local_1c = (char *)0x0;
            std::exception::exception((exception *)local_2c,&local_1c);
            local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_2c,&DAT_00c857a8);
          }
          *(int *)(puVar4 + 4) = iVar3;
          *(int *)iVar3 = iVar3;
          *(int *)(*(int *)(puVar4 + 4) + 4) = *(int *)(puVar4 + 4);
          *(int *)(*(int *)(puVar4 + 4) + 8) = *(int *)(puVar4 + 4);
          *(undefined1 *)(*(int *)(puVar4 + 4) + 0x20) = 1;
          *(undefined1 *)(*(int *)(puVar4 + 4) + 0x21) = 1;
          puVar7 = puVar4;
        }
        local_8 = 0xffffffff;
        *puVar7 = *(ushort *)(param_1 + 4);
        local_14 = (ushort *)(uint)*(ushort *)(param_1 + 0x88);
        if (puVar7[1] != *(ushort *)(param_1 + 0x88)) {
          FUN_00597b70(uVar2);
          puVar7[1] = (ushort)local_14;
        }
        local_18 = (uint)*(ushort *)(param_1 + 4);
        local_14 = puVar7;
        uVar5 = FUN_0057ef20();
        FUN_0082f200(in_ECX + 0x12,uVar5);
      }
      else {
        puVar7 = *(ushort **)(local_1c + 0x10);
        *puVar7 = uVar1;
        uVar1 = *(ushort *)(param_1 + 0x88);
        if (puVar7[1] != uVar1) {
          FUN_00597b70(uVar2);
          puVar7[1] = uVar1;
        }
      }
      local_20[4] = (int)puVar7;
      ExceptionList = local_10;
      return;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return;
}


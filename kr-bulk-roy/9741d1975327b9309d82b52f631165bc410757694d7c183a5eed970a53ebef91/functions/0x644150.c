
/* WARNING: Removing unreachable block (ram,0x0064489b) */
/* WARNING: Removing unreachable block (ram,0x006448a2) */
/* WARNING: Removing unreachable block (ram,0x0064478a) */
/* WARNING: Removing unreachable block (ram,0x00644697) */
/* WARNING: Removing unreachable block (ram,0x00644680) */
/* WARNING: Removing unreachable block (ram,0x0064477a) */
/* WARNING: Removing unreachable block (ram,0x0064478e) */
/* WARNING: Removing unreachable block (ram,0x0064487e) */
/* WARNING: Removing unreachable block (ram,0x00644885) */
/* WARNING: Removing unreachable block (ram,0x006448d0) */

void FUN_00644150(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  code *pcVar4;
  char cVar5;
  uint uVar6;
  int *in_ECX;
  int *piVar7;
  int iVar8;
  int local_9c;
  int local_7c;
  int *local_70;
  uint local_58;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0092d1ae;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  uStack_7 = 0;
  FUN_00645e40();
  FUN_005a9f40();
  FUN_00645f20();
  FUN_005a9f40();
  FUN_00646000();
  FUN_005a9f40();
  FUN_006460e0();
  FUN_005a9f40();
  FUN_006461c0();
  FUN_005a9f40();
  FUN_006462a0();
  FUN_005a9f40();
  FUN_00646380();
  FUN_005a9f40();
  FUN_00646460();
  FUN_005a9f40();
  FUN_00646540();
  FUN_005a9f40();
  FUN_00646620();
  FUN_005a9f40();
  FUN_0040b670();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  FUN_005740f0();
  if (local_70 == (int *)DAT_00fe5ac8) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 3;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  FUN_005740f0();
  if (local_70 == (int *)DAT_00fe5ac8) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 4;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  FUN_005740f0();
  if (local_70 == (int *)DAT_00fe5ac8) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 5;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 1;
  }
  FUN_005740f0();
  if (local_70 != (int *)DAT_00fe5ac8) {
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 6;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 1;
    }
    FUN_005740f0();
    if (local_70 != (int *)DAT_00fe5ac8) {
      FUN_00757710();
      local_70 = in_ECX + 0x4f;
      local_7c = 0;
      do {
        if (*(int *)(in_ECX[0x44] + 0xd8) != 0) {
          FUN_0040acb0();
        }
        iVar8 = *(int *)(in_ECX[0x44] + 0xd8);
        if ((iVar8 == 0) || (FUN_0082ef00(), local_9c == *(int *)(iVar8 + 0xac))) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = *(int **)(local_9c + 0x10);
        }
        local_70[-10] = (int)piVar7;
        (**(code **)(*piVar7 + 0x40))();
        iVar8 = 0xa8;
        do {
          (**(code **)(**(int **)(iVar8 + *local_70) + 0xa0))();
          iVar8 = iVar8 + 4;
        } while (iVar8 < 0xc0);
        FUN_00645060();
        FUN_0040ef80();
        FUN_00424c80(L"Filter{0}");
        if ((DAT_00faaf7c & 1) == 0) {
          DAT_00faaf7c = DAT_00faaf7c | 1;
          local_8 = 8;
          FUN_0058d410();
          _atexit((_func_4879 *)&LAB_00bccdc0);
        }
        _local_8 = CONCAT31(uStack_7,9);
        cVar5 = FUN_0058ef10();
        if (cVar5 != '\0') {
          FUN_008935e3();
        }
        local_8 = 1;
        if (7 < local_58) {
          FUN_0089120c();
        }
        if (cVar5 != '\0') {
          FUN_00645170();
        }
        (**(code **)(*(int *)*local_70 + 0xd4))();
        local_7c = local_7c + 1;
        local_70 = local_70 + 1;
      } while (local_7c < 5);
      if ((DAT_00faaf7c & 1) == 0) {
        DAT_00faaf7c = DAT_00faaf7c | 1;
        local_8 = 10;
        FUN_0058d410();
        _atexit((_func_4879 *)&LAB_00bccdc0);
      }
      local_8 = 0xb;
      cVar5 = FUN_0058ef10();
      if (cVar5 != '\0') {
        FUN_008935e3();
      }
      local_8 = 1;
      *(undefined4 *)(in_ECX[0x44] + 200) = 1;
      piVar7 = (int *)in_ECX[0x44];
      puVar1 = (undefined4 *)piVar7[0x19];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        if ((*(int *)(puVar2[2] + 0x60) != 0) &&
           (piVar3 = *(int **)(puVar2[2] + 0x1c), piVar3[2] != 6)) {
          (**(code **)(*piVar3 + 0x30))();
        }
      }
      (**(code **)(*piVar7 + 0x128))();
      FUN_0040b5b0();
      (**(code **)(*(int *)in_ECX[0x44] + 200))();
      if ((DAT_00faaf7c & 1) == 0) {
        DAT_00faaf7c = DAT_00faaf7c | 1;
        local_8 = 0xc;
        FUN_0058d410();
        _atexit((_func_4879 *)&LAB_00bccdc0);
        local_8 = 1;
      }
      FUN_0058eb30();
      *(undefined1 *)((int)in_ECX + 0xea) = 0;
      (**(code **)(*in_ECX + 0x16c))();
      in_ECX[10] = in_ECX[10] | 4;
      *(uint *)(in_ECX[0x20] + 0x28) = *(uint *)(in_ECX[0x20] + 0x28) | 4;
      (**(code **)(*(int *)in_ECX[0x54] + 0xa0))();
      ExceptionList = local_10;
      __security_check_cookie(uVar6 ^ (uint)&stack0xfffffffc);
      return;
    }
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



int FUN_007dcfb0(undefined1 *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int local_c;
  uint local_8;
  
  puVar3 = param_1;
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 100);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(puVar3 + 0x7c) != *(int *)(puVar3 + 0x80)) {
    iVar4 = *(int *)(*(int *)(puVar3 + 0x80) + -4);
    FUN_007be5b0();
    if (*(int *)(puVar3 + 0x7c) != *(int *)(puVar3 + 0x80)) {
      *(int *)(puVar3 + 0x80) = *(int *)(puVar3 + 0x80) + -4;
    }
    LeaveCriticalSection(lpCriticalSection);
    return iVar4;
  }
  LeaveCriticalSection(lpCriticalSection);
  iVar4 = FUN_00891268(0x7c);
  if (iVar4 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_007bd7e0(*(undefined4 *)(puVar3 + 0x48));
  }
  local_8 = 0;
  uVar5 = *(int *)(puVar3 + 0x50) - *(int *)(puVar3 + 0x4c) >> 2;
  if (uVar5 != 0) {
    do {
      puVar6 = (undefined1 *)FUN_00891268(0xc);
      puVar7 = (undefined1 *)0x0;
      if (puVar6 != (undefined1 *)0x0) {
        *(undefined4 *)(puVar6 + 4) = 0;
        *(undefined4 *)(puVar6 + 8) = 0;
        *puVar6 = 0;
        puVar7 = puVar6;
      }
      *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(*(int *)(puVar3 + 0x4c) + local_8 * 4);
      puVar1 = *(undefined4 **)(local_c + 8);
      param_1 = puVar7;
      if (&param_1 < puVar1) {
        puVar2 = *(undefined4 **)(local_c + 4);
        if (&param_1 < puVar2) goto LAB_007dd0b7;
        if (puVar1 == *(undefined4 **)(local_c + 0xc)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(local_c + 8) != (undefined4 *)0x0) {
          **(undefined4 **)(local_c + 8) =
               *(undefined4 *)(*(int *)(local_c + 4) + ((int)&param_1 - (int)puVar2 >> 2) * 4);
        }
      }
      else {
LAB_007dd0b7:
        if (puVar1 == *(undefined4 **)(local_c + 0xc)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(local_c + 8) != (undefined4 *)0x0) {
          **(undefined4 **)(local_c + 8) = puVar7;
        }
      }
      *(int *)(local_c + 8) = *(int *)(local_c + 8) + 4;
      local_8 = local_8 + 1;
    } while (local_8 < uVar5);
  }
  if (0 < *(int *)(puVar3 + 0x44)) {
    FUN_007bdf90();
  }
  return local_c;
}


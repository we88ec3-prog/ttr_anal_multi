
void FUN_0077d450(undefined4 *param_1)

{
  LPCWSTR pWVar1;
  char cVar2;
  WCHAR WVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  LPCWSTR pWVar10;
  LPCWSTR name;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_00907c3d;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FoxUI::FXUIFontSet::vftable;
  local_8 = 1;
  puVar4 = (undefined4 *)param_1[4];
  puVar5 = (undefined4 *)*puVar4;
  while (puVar5 != puVar4) {
    uVar6 = *(uint *)(puVar5[4] + 0x54);
    name = (LPCWSTR)(puVar5[4] + 0x40);
    pWVar10 = name;
    if (7 < uVar6) {
      pWVar10 = *(LPCWSTR *)name;
    }
    pWVar1 = pWVar10 + 1;
    do {
      WVar3 = *pWVar10;
      pWVar10 = pWVar10 + 1;
    } while (WVar3 != L'\0');
    if ((int)pWVar10 - (int)pWVar1 >> 1 != 0) {
      if (7 < uVar6) {
        name = *(LPCWSTR *)name;
      }
      RemoveFontResourceExW(name,0x10,(PVOID)0x0);
    }
    if ((int *)puVar5[4] != (int *)0x0) {
      (**(code **)(*(int *)puVar5[4] + 0x1c))(1,uVar9);
      puVar5[4] = 0;
    }
    if (*(char *)((int)puVar5 + 0x15) == '\0') {
      puVar7 = (undefined4 *)puVar5[2];
      if (*(char *)((int)puVar7 + 0x15) == '\0') {
        cVar2 = *(char *)((int)*puVar7 + 0x15);
        puVar5 = puVar7;
        puVar7 = (undefined4 *)*puVar7;
        while (cVar2 == '\0') {
          cVar2 = *(char *)((int)*puVar7 + 0x15);
          puVar5 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      else {
        cVar2 = *(char *)((int)puVar5[1] + 0x15);
        puVar8 = (undefined4 *)puVar5[1];
        puVar7 = puVar5;
        while ((puVar5 = puVar8, cVar2 == '\0' && (puVar7 == (undefined4 *)puVar5[2]))) {
          cVar2 = *(char *)((int)puVar5[1] + 0x15);
          puVar8 = (undefined4 *)puVar5[1];
          puVar7 = puVar5;
        }
      }
    }
  }
  uVar9 = (uint)local_8 >> 8;
  local_8 = CONCAT31((int3)uVar9,2);
  FUN_005540c0(*(undefined4 *)param_1[4],(undefined4 *)param_1[4]);
  FUN_0089120c(param_1[4]);
  *param_1 = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}


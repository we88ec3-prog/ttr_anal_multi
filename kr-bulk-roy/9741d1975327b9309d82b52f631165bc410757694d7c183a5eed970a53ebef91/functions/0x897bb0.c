
/* Library Function - Single Match
    _qsort
   
   Library: Visual Studio 2010 Release */

void __cdecl
_qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
  undefined1 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  size_t sVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 auStack_104 [30];
  undefined4 auStack_8c [30];
  size_t local_14;
  int local_10;
  undefined1 *local_c;
  undefined1 *local_8;
  
  if ((_Base == (void *)0x0) && (_NumOfElements != 0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
    return;
  }
  if ((_SizeOfElements == 0) || (_PtFuncCompare == (_PtFuncCompare *)0x0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
  }
  else if (1 < _NumOfElements) {
    local_10 = 0;
    local_8 = _Base;
    local_c = (undefined1 *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
LAB_00897c20:
    while (puVar7 = local_8, puVar10 = local_c,
          uVar3 = (uint)((int)local_c - (int)local_8) / _SizeOfElements + 1, 8 < uVar3) {
      puVar9 = local_8 + _SizeOfElements * (uVar3 >> 1);
      iVar4 = (*_PtFuncCompare)(local_8,puVar9);
      if ((0 < iVar4) && (puVar7 != puVar9)) {
        puVar5 = puVar9;
        local_14 = _SizeOfElements;
        do {
          local_14 = local_14 - 1;
          uVar1 = puVar5[(int)puVar7 - (int)puVar9];
          puVar5[(int)puVar7 - (int)puVar9] = *puVar5;
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
        } while (local_14 != 0);
      }
      iVar4 = (*_PtFuncCompare)(puVar7,puVar10);
      puVar5 = puVar7;
      if ((0 < iVar4) && (puVar7 != puVar10)) {
        puVar6 = puVar10;
        sVar8 = _SizeOfElements;
        do {
          uVar1 = puVar6[(int)puVar7 - (int)puVar10];
          puVar6[(int)puVar7 - (int)puVar10] = *puVar6;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 1;
          sVar8 = sVar8 - 1;
          puVar5 = local_8;
        } while (sVar8 != 0);
      }
      iVar4 = (*_PtFuncCompare)(puVar9,puVar10);
      if ((0 < iVar4) && (puVar9 != puVar10)) {
        puVar7 = puVar10;
        sVar8 = _SizeOfElements;
        do {
          uVar1 = puVar7[(int)puVar9 - (int)puVar10];
          puVar7[(int)puVar9 - (int)puVar10] = *puVar7;
          *puVar7 = uVar1;
          puVar7 = puVar7 + 1;
          sVar8 = sVar8 - 1;
          puVar5 = local_8;
        } while (sVar8 != 0);
      }
LAB_00897cf0:
      if (puVar5 < puVar9) {
        do {
          puVar5 = puVar5 + _SizeOfElements;
          if (puVar9 <= puVar5) goto LAB_00897d10;
          iVar4 = (*_PtFuncCompare)(puVar5,puVar9);
        } while (iVar4 < 1);
        if (puVar9 <= puVar5) goto LAB_00897d10;
      }
      else {
LAB_00897d10:
        do {
          puVar5 = puVar5 + _SizeOfElements;
          if (local_c < puVar5) break;
          iVar4 = (*_PtFuncCompare)(puVar5,puVar9);
        } while (iVar4 < 1);
      }
      do {
        puVar10 = puVar10 + -_SizeOfElements;
        if (puVar10 <= puVar9) break;
        iVar4 = (*_PtFuncCompare)(puVar10,puVar9);
      } while (0 < iVar4);
      if (puVar5 <= puVar10) {
        if (puVar5 != puVar10) {
          puVar7 = puVar10;
          local_14 = _SizeOfElements;
          do {
            local_14 = local_14 - 1;
            uVar1 = puVar7[(int)puVar5 - (int)puVar10];
            puVar7[(int)puVar5 - (int)puVar10] = *puVar7;
            *puVar7 = uVar1;
            puVar7 = puVar7 + 1;
          } while (local_14 != 0);
        }
        if (puVar9 == puVar10) {
          puVar9 = puVar5;
        }
        goto LAB_00897cf0;
      }
      puVar10 = puVar10 + _SizeOfElements;
      if (puVar9 < puVar10) {
        do {
          puVar10 = puVar10 + -_SizeOfElements;
          if (puVar10 <= puVar9) goto LAB_00897d90;
          iVar4 = (*_PtFuncCompare)(puVar10,puVar9);
        } while (iVar4 == 0);
        if (puVar10 <= puVar9) goto LAB_00897d90;
      }
      else {
LAB_00897d90:
        do {
          puVar10 = puVar10 + -_SizeOfElements;
          if (puVar10 <= local_8) break;
          iVar4 = (*_PtFuncCompare)(puVar10,puVar9);
        } while (iVar4 == 0);
      }
      puVar9 = local_8;
      puVar7 = local_c;
      if ((int)puVar10 - (int)local_8 < (int)local_c - (int)puVar5) goto LAB_00897de3;
      if (local_8 < puVar10) {
        auStack_8c[local_10] = local_8;
        auStack_104[local_10] = puVar10;
        local_10 = local_10 + 1;
      }
      local_8 = puVar5;
      if (puVar7 <= puVar5) goto LAB_00897e11;
    }
    shortsort(local_8,_SizeOfElements,_PtFuncCompare);
    goto LAB_00897e11;
  }
  return;
LAB_00897de3:
  if (puVar5 < local_c) {
    auStack_8c[local_10] = puVar5;
    auStack_104[local_10] = local_c;
    local_10 = local_10 + 1;
  }
  local_c = puVar10;
  if (puVar10 <= puVar9) {
LAB_00897e11:
    local_10 = local_10 + -1;
    if (local_10 < 0) {
      return;
    }
    local_c = (undefined1 *)auStack_104[local_10];
    local_8 = (undefined1 *)auStack_8c[local_10];
  }
  goto LAB_00897c20;
}


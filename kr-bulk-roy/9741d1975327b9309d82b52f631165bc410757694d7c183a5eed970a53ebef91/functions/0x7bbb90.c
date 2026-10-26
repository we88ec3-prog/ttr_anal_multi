
void FUN_007bbb90(void *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937f86;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  uVar6 = FUN_0079a5f0(&DAT_00fb76a8);
  uVar3 = DAT_00fb79e8 & 1;
  *(undefined4 *)((int)param_1 + 0x58) = uVar6;
  if (uVar3 == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  local_18 = DAT_00fb76a8;
  D3DXCreateTexture(*(undefined4 *)((int)param_1 + 0x58),0x100,0x100,0,0,0x1a,1,
                    (undefined4 *)((int)param_1 + 0x5c));
  D3DXFillTexture(*(undefined4 *)((int)param_1 + 0x5c),FUN_007e4d00,0);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  piVar8 = (int *)**(int **)((int)param_1 + 0x28);
  if (piVar8 != *(int **)((int)param_1 + 0x28)) {
    do {
      iVar2 = piVar8[10];
      piVar9 = piVar8 + 3;
      local_14 = (int *)0x0;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      FUN_0079a5f0(&DAT_00fb76a8);
      iVar7 = FUN_00737d40();
      if (iVar7 == 0) {
        if (0xf < (uint)piVar8[8]) {
          piVar9 = (int *)*piVar9;
        }
        local_1c = iVar7;
        (**(code **)(*local_18 + 0x50))(piVar9,local_14,&local_1c);
        (**(code **)(*local_14 + 8))(local_14);
      }
      *(undefined4 *)(iVar2 + 0x1c) = 1;
      if (*(char *)((int)piVar8 + 0x2d) == '\0') {
        piVar9 = (int *)piVar8[2];
        if (*(char *)((int)piVar9 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar9 + 0x2d);
          piVar8 = piVar9;
          piVar9 = (int *)*piVar9;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar9 + 0x2d);
            piVar8 = piVar9;
            piVar9 = (int *)*piVar9;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x2d);
          piVar4 = (int *)piVar8[1];
          piVar9 = piVar8;
          while ((piVar8 = piVar4, cVar1 == '\0' && (piVar9 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x2d);
            piVar4 = (int *)piVar8[1];
            piVar9 = piVar8;
          }
        }
      }
    } while (piVar8 != *(int **)((int)param_1 + 0x28));
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 4;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  DAT_00d63c6c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_00d63c68 = 1;
  __beginthread(FUN_007bca20,0,param_1);
  ExceptionList = local_10;
  return;
}


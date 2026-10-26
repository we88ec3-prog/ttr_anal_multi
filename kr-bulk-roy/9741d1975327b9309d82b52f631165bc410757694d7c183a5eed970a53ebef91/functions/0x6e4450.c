
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4450(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  void *_Dst;
  int in_ECX;
  int in_EDX;
  int iVar8;
  int *piVar9;
  int iVar10;
  int local_74;
  int local_70;
  int local_6c;
  void *local_64;
  int local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 *local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f3e8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2c = param_2;
  local_38 = in_ECX;
  local_30 = in_EDX;
  piVar2 = (int *)FUN_006dfb80(local_14);
  (**(code **)(*piVar2 + 0x20))(piVar2,*param_2,&local_24);
  if (*(int *)(in_EDX + 0x10) == 1) {
    local_3c = *(uint *)(in_ECX + 0xc);
  }
  else if (*(int *)(in_EDX + 0x10) == 0) {
    local_3c = (-(uint)((*(uint *)(param_2[0x15] + 0x24) & 0x10000) != 0) & 0x20) + 0x20;
  }
  else {
    uVar6 = *(uint *)(param_2[0x15] + 0x24) & 0x10000;
    local_3c = *(uint *)(in_ECX + 0xc);
    if ((uVar6 == 0) && ((local_3c & 0xc0) != 0)) {
      local_3c = local_3c & 0xffffff3f | 0x20;
    }
    if ((local_3c & 0xe0) == 0) {
      if (uVar6 == 0) {
        local_3c = local_3c | 0x20;
      }
      else {
        local_3c = local_3c | 0x40;
      }
    }
  }
  if (*(int *)(in_EDX + 0x14) == 1) {
    local_74 = *(int *)(in_ECX + 0x10);
    local_70 = *(int *)(in_ECX + 0x14);
  }
  else {
    if ((*(int *)(in_EDX + 0x14) == 2) && (in_ECX != 0)) {
      local_20 = *(undefined4 *)(in_ECX + 0x14);
      local_24 = *(undefined4 *)(in_ECX + 0x10);
    }
    else if (param_2[4] == 0) {
      if (DAT_00fba7cc == (void *)0x0) {
        iVar8 = FUN_00891268(0x1380);
        if (iVar8 == 0) {
          DAT_00fba7cc = (void *)0x0;
        }
        else {
          DAT_00fba7cc = (void *)FUN_006df3d0();
        }
      }
      iVar8 = FUN_006e1260(DAT_00fba7cc);
      if (0 < iVar8) {
        uVar3 = FUN_006df6d0();
        uVar3 = FUN_006e1260(uVar3);
        uVar4 = FUN_006df6d0();
        local_20 = FUN_006e12a0(uVar4);
        *(undefined4 *)(local_30 + 0x14) = 2;
        local_24 = uVar3;
      }
    }
    else {
      local_20 = 0x300;
      local_24 = 0x400;
    }
    FUN_006e4e90(&local_74,local_24,local_20,local_1c,local_18);
    in_EDX = local_30;
  }
  if (*(int *)(in_EDX + 0x1c) == 1) {
    local_4c = *(uint *)(in_ECX + 0x1c);
  }
  else if (*(int *)(in_EDX + 0x1c) == 0) {
    local_4c = 2;
  }
  else {
    local_4c = *(uint *)(in_ECX + 0x1c);
    if (local_4c < 4) {
      if (local_4c == 0) {
        local_4c = 1;
      }
    }
    else {
      local_4c = 3;
    }
  }
  if ((in_ECX == 0) || (*(int *)(in_ECX + 0x28) == 1)) {
    iVar8 = *(int *)(in_EDX + 0x20);
    if (iVar8 == 1) {
      local_40 = *(int *)(in_ECX + 0x20);
      local_44 = *(uint *)(in_ECX + 0x24);
    }
    else {
      if ((iVar8 == 0) || (iVar8 != 2)) goto LAB_006e46be;
      piVar2 = param_2 + 9;
      local_40 = 0;
      local_44 = 0;
      local_34 = 0;
      if (0 < *piVar2) {
        piVar9 = (int *)param_2[0xb];
        local_50 = *(int *)(in_ECX + 0x20);
        local_54 = param_2[8] - (int)piVar9;
        do {
          iVar8 = *(int *)(local_54 + (int)piVar9);
          uVar6 = iVar8 - local_50 >> 0x1f;
          local_58 = (iVar8 - local_50 ^ uVar6) - uVar6;
          uVar6 = local_40 - local_50 >> 0x1f;
          if (local_58 < (int)((local_40 - local_50 ^ uVar6) - uVar6)) {
            local_44 = *piVar9 - 1U;
            local_40 = iVar8;
            if (*(uint *)(local_38 + 0x24) <= *piVar9 - 1U) {
              local_44 = *(uint *)(local_38 + 0x24);
            }
          }
          local_34 = local_34 + 1;
          piVar9 = piVar9 + 1;
          param_2 = local_2c;
          in_EDX = local_30;
          in_ECX = local_38;
        } while (local_34 < *piVar2);
      }
    }
  }
  else {
LAB_006e46be:
    local_40 = 0;
    local_44 = 0;
  }
  if (*(int *)(in_EDX + 0x24) == 1) {
    local_48 = *(int *)(in_ECX + 0x28);
  }
  else if ((*(int *)(in_EDX + 0x24) == 0) ||
          (((local_48 = *(int *)(in_ECX + 0x28), local_48 != 1 && (local_48 != 2)) &&
           (local_48 != 3)))) {
    local_48 = 1;
  }
  local_64 = (void *)0x0;
  local_60 = 0;
  local_5c = 0;
  local_8 = 0;
  FUN_006eacd0();
  switch(param_2[3]) {
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x20:
    local_28 = 8;
    break;
  case 0x17:
  case 0x18:
  case 0x19:
    local_28 = 5;
    break;
  case 0x1a:
  case 0x1e:
    local_28 = 4;
    break;
  case 0x1b:
  case 0x1d:
    local_28 = 2;
    break;
  default:
    local_28 = 0;
    break;
  case 0x1f:
  case 0x23:
    local_28 = 10;
    break;
  case 0x24:
    local_28 = 0x10;
  }
  iVar8 = 0;
  if (in_ECX != 0) {
    switch(*(undefined4 *)(in_ECX + 0x38)) {
    case 0x46:
    case 0x50:
      iVar8 = 0x10;
      break;
    case 0x47:
    case 0x52:
      iVar8 = 0x20;
      break;
    default:
      iVar8 = 0;
      break;
    case 0x49:
      iVar8 = 0xf;
      break;
    case 0x4b:
    case 0x4d:
    case 0x4f:
    case 0x53:
      iVar8 = 0x18;
    }
  }
  local_34 = 0;
  if (0 < (int)local_2c[6]) {
    do {
      switch(*(undefined4 *)(local_2c[5] + local_34 * 4)) {
      case 0x46:
      case 0x50:
        iVar5 = 0x10;
        break;
      case 0x47:
      case 0x52:
        iVar5 = 0x20;
        break;
      default:
        iVar5 = 0;
        break;
      case 0x49:
        iVar5 = 0xf;
        break;
      case 0x4b:
      case 0x4d:
      case 0x4f:
      case 0x53:
        iVar5 = 0x18;
      }
      if (*(int *)(local_30 + 0x28) == 1) {
        uVar6 = -(uint)(iVar5 != iVar8) & 10000;
      }
      else {
        iVar10 = iVar8;
        if (*(int *)(local_30 + 0x28) == 0) {
          iVar10 = local_28 * 4;
        }
        uVar6 = iVar5 - iVar10 >> 0x1f;
        uVar6 = (iVar5 - iVar10 ^ uVar6) - uVar6;
      }
      iVar5 = FUN_006ed1c0();
      if (-1 < iVar5) {
        *(uint *)((int)local_64 + local_60 * 4) = uVar6;
        local_60 = local_60 + 1;
      }
      local_34 = local_34 + 1;
      in_ECX = local_38;
    } while (local_34 < (int)local_2c[6]);
  }
  puVar1 = local_2c;
  iVar8 = 0;
  if (in_ECX != 0) {
    switch(*(undefined4 *)(in_ECX + 0x38)) {
    default:
      iVar8 = 0;
      break;
    case 0x49:
      iVar8 = 1;
      break;
    case 0x4b:
    case 0x53:
      iVar8 = 8;
      break;
    case 0x4f:
      iVar8 = 4;
    }
  }
  iVar5 = 0;
  if (0 < (int)local_2c[6]) {
    do {
      iVar10 = *(int *)((int)local_64 + iVar5 * 4);
      switch(*(undefined4 *)(local_2c[5] + iVar5 * 4)) {
      default:
        iVar7 = 0;
        break;
      case 0x49:
        iVar7 = 1;
        break;
      case 0x4b:
      case 0x53:
        iVar7 = 8;
        break;
      case 0x4f:
        iVar7 = 4;
      }
      if (*(int *)(local_30 + 0x2c) == 1) {
        if (iVar7 != iVar8) {
          iVar10 = iVar10 + 10000;
        }
      }
      else {
        if (*(int *)(local_30 + 0x2c) != 0) {
          uVar6 = iVar7 - iVar8 >> 0x1f;
          iVar7 = (iVar7 - iVar8 ^ uVar6) - uVar6;
        }
        iVar10 = iVar10 + iVar7;
      }
      if ((-1 < iVar5) && (iVar5 < local_60)) {
        *(int *)((int)local_64 + iVar5 * 4) = iVar10;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)local_2c[6]);
  }
  iVar5 = -1;
  iVar10 = 0;
  iVar8 = 100000;
  if (0 < (int)local_2c[6]) {
    do {
      iVar7 = *(int *)((int)local_64 + iVar10 * 4);
      if (iVar7 < iVar8) {
        iVar8 = iVar7;
        iVar5 = iVar10;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)local_2c[6]);
    if (-1 < iVar5) {
      local_54 = *(undefined4 *)(local_2c[5] + iVar5 * 4);
      local_34 = 1;
      goto LAB_006e4950;
    }
  }
  local_34 = 0;
  local_54 = 0;
LAB_006e4950:
  if (*(int *)(local_30 + 0x30) == 1) {
    local_28 = *(uint *)(local_38 + 0x3c);
  }
  else if (*(int *)(local_30 + 0x30) == 0) {
    local_28 = 0;
    if (local_34 != 0) {
      local_28 = 2;
    }
  }
  else {
    local_28 = *(uint *)(local_38 + 0x3c);
    if (local_34 != 0) {
      local_28 = local_28 | 2;
    }
  }
  if (local_2c[4] == 0) {
    if (*(int *)(local_30 + 0x34) == 1) {
      local_6c = *(int *)(local_38 + 0x40);
    }
    else {
      if (*(int *)(local_30 + 0x34) == 2) {
        local_1c = *(int *)(local_38 + 0x40);
      }
      local_6c = 0;
      local_58 = local_1c;
      if (local_1c != 0) {
        iVar8 = *(int *)(local_2c[0x14] + 0x654);
        iVar5 = 100000;
        local_50 = 0;
        if (0 < iVar8) {
          piVar2 = *(int **)(local_2c[0x14] + 0x650);
          do {
            iVar10 = piVar2[2];
            if (((piVar2[3] == local_2c[2]) && (piVar2[1] == local_70)) &&
               ((*piVar2 == local_74 &&
                ((uVar6 = iVar10 - local_1c >> 0x1f, iVar7 = (iVar10 - local_1c ^ uVar6) - uVar6,
                 iVar7 < iVar5 && (iVar5 = iVar7, local_6c = iVar10, iVar7 == 0)))))) break;
            local_50 = local_50 + 1;
            piVar2 = piVar2 + 4;
          } while (local_50 < iVar8);
        }
      }
    }
  }
  else {
    local_6c = 0;
  }
  if (*(int *)(local_30 + 0x38) == 1) {
    local_30 = *(int *)(local_38 + 0x44);
  }
  else {
    if ((((*(int *)(local_30 + 0x38) != 0) && (iVar8 = local_2c[0xf], 0 < iVar8)) && (0 < iVar8)) &&
       (-1 < iVar8)) {
      local_30 = *(int *)(local_38 + 0x44);
      piVar2 = (int *)local_2c[0xe];
      iVar5 = 0;
      do {
        if (local_30 == *piVar2) {
          if (iVar5 != -1) goto LAB_006e4a8d;
          break;
        }
        iVar5 = iVar5 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar5 < iVar8);
    }
    local_30 = 0;
  }
LAB_006e4a8d:
  _memset(param_1,0,0x48);
  _Dst = DAT_00fba7cc;
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  param_1[4] = local_74;
  param_1[3] = local_3c;
  param_1[5] = local_70;
  param_1[6] = puVar1[3];
  param_1[7] = local_4c;
  param_1[8] = local_40;
  param_1[9] = local_44;
  param_1[10] = local_48;
  if (puVar1[4] == 0) {
    if (_Dst == (void *)0x0) {
      _Dst = (void *)FUN_00891268(0x1380);
      if (_Dst == (void *)0x0) {
        _Dst = (void *)0x0;
        DAT_00fba7cc = _Dst;
      }
      else {
        *(undefined8 *)((int)_Dst + 0x1350) = 0;
        *(undefined4 *)((int)_Dst + 0x1370) = 1;
        *(undefined8 *)((int)_Dst + 0x1358) = 0;
        *(undefined4 *)((int)_Dst + 0x1374) = 1;
        *(undefined4 *)((int)_Dst + 0x1360) = 0x1e;
        *(undefined4 *)((int)_Dst + 0x1378) = 0;
        *(undefined8 *)((int)_Dst + 0x1368) = 0x3fa1111111111111;
        if ((_DAT_00fe4b14 & 1) == 0) {
          _DAT_00fe4b14 = _DAT_00fe4b14 | 1;
          DAT_00fe36b0 = 0;
          _DAT_00fe36b4 = 0;
          _DAT_00fe36b8 = 0;
          DAT_00fe36bc = 0;
          _DAT_00fe36c0 = 0;
          _DAT_00fe36c4 = 0;
          DAT_00fe36c8 = 0;
          _DAT_00fe36cc = 0;
          _DAT_00fe36d0 = 0;
          _atexit((_func_4879 *)&LAB_00bd0720);
        }
        _memset(_Dst,0,0x1350);
        DAT_00d63d09 = '\x01';
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        *(undefined4 *)((int)_Dst + 0x344) = 0xffffffff;
        *(undefined4 *)((int)_Dst + 0x348) = 0xffffffff;
        *(undefined4 *)((int)_Dst + 0x330) = 0xffffffff;
        *(undefined4 *)((int)_Dst + 0x358) = 0xffffffff;
        *(undefined1 *)((int)_Dst + 0x309) = 1;
        *(undefined1 *)((int)_Dst + 0x2fd) = 1;
        *(undefined1 *)((int)_Dst + 0x2d1) = 1;
        *(undefined1 *)((int)_Dst + 0x31a) = 1;
        *(undefined1 *)((int)_Dst + 0x2d3) = 1;
        DAT_00fba7cc = _Dst;
      }
    }
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    uVar3 = *(undefined4 *)((int)_Dst + 0x164);
  }
  else {
    if (_Dst == (void *)0x0) {
      _Dst = (void *)FUN_00891268(0x1380);
      if (_Dst == (void *)0x0) {
        _Dst = (void *)0x0;
        DAT_00fba7cc = _Dst;
      }
      else {
        *(undefined8 *)((int)_Dst + 0x1350) = 0;
        *(undefined4 *)((int)_Dst + 0x1370) = 1;
        *(undefined8 *)((int)_Dst + 0x1358) = 0;
        *(undefined4 *)((int)_Dst + 0x1374) = 1;
        *(undefined4 *)((int)_Dst + 0x1360) = 0x1e;
        *(undefined4 *)((int)_Dst + 0x1378) = 0;
        *(undefined8 *)((int)_Dst + 0x1368) = 0x3fa1111111111111;
        if ((_DAT_00fe4b14 & 1) == 0) {
          _DAT_00fe4b14 = _DAT_00fe4b14 | 1;
          DAT_00fe36b0 = 0;
          _DAT_00fe36b4 = 0;
          _DAT_00fe36b8 = 0;
          DAT_00fe36bc = 0;
          _DAT_00fe36c0 = 0;
          _DAT_00fe36c4 = 0;
          DAT_00fe36c8 = 0;
          _DAT_00fe36cc = 0;
          _DAT_00fe36d0 = 0;
          _atexit((_func_4879 *)&LAB_00bd0720);
        }
        _memset(_Dst,0,0x1350);
        DAT_00d63d09 = '\x01';
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        *(undefined4 *)((int)_Dst + 0x344) = 0xffffffff;
        *(undefined4 *)((int)_Dst + 0x348) = 0xffffffff;
        *(undefined4 *)((int)_Dst + 0x330) = 0xffffffff;
        *(undefined4 *)((int)_Dst + 0x358) = 0xffffffff;
        *(undefined1 *)((int)_Dst + 0x309) = 1;
        *(undefined1 *)((int)_Dst + 0x2fd) = 1;
        *(undefined1 *)((int)_Dst + 0x2d1) = 1;
        *(undefined1 *)((int)_Dst + 0x31a) = 1;
        *(undefined1 *)((int)_Dst + 0x2d3) = 1;
        DAT_00fba7cc = _Dst;
      }
    }
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    uVar3 = *(undefined4 *)((int)_Dst + 0x168);
  }
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  param_1[0xb] = uVar3;
  uVar3 = puVar1[4];
  param_1[0xe] = local_54;
  param_1[0x11] = local_30;
  param_1[0xc] = uVar3;
  param_1[0xd] = local_34;
  param_1[0xf] = local_28;
  param_1[0x10] = local_6c;
  if (local_64 != (void *)0x0) {
    _free(local_64);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


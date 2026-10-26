
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490820(int param_1,HWND param_2,uint param_3,WPARAM param_4,uint param_5,
                 undefined1 *param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  WPARAM wParam;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_44 [4];
  undefined1 *local_40;
  HWND local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  tagRECT local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093713c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  local_3c = param_2;
  local_38 = param_5;
  local_40 = param_6;
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0(uVar3);
    DAT_00fc18d8 = 1;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  iVar4 = FUN_0048a690(&DAT_00fc1840,param_2,&param_4);
  if (iVar4 == 0) {
    if ((_DAT_00fc183c & 1) == 0) {
      _DAT_00fc183c = _DAT_00fc183c | 1;
      FUN_006f1ff0(uVar3);
      DAT_00fc18d8 = 1;
      _atexit((_func_4879 *)&LAB_00bce3a0);
    }
    if (DAT_00fc18d8 != 0) {
      if ((_DAT_00fc183c & 1) == 0) {
        _DAT_00fc183c = _DAT_00fc183c | 1;
        FUN_006f1ff0(uVar3);
        DAT_00fc18d8 = 1;
        _atexit((_func_4879 *)&LAB_00bce3a0);
      }
      DAT_00fc18d8 = 0;
      local_30 = 0;
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 0;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      FUN_0058a870(&DAT_00faadd8,local_3c,param_3,param_4,local_38);
    }
    *local_40 = 1;
  }
  else {
    local_34 = 0;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    uVar3 = local_38;
    wParam = param_4;
    FUN_0058a870(&DAT_00faadd8,local_3c,param_3,param_4,local_38);
    if (local_34 == 1) {
      *local_40 = 1;
      goto LAB_00490c54;
    }
    if (param_3 < 0x105) {
      if (param_3 == 0x104) {
        if (wParam == 0xd) {
          if ((uVar3 & 0x20000000) != 0) {
            FUN_006e71f0(1,1);
            FUN_006e2e20();
            FUN_006e71f0(0,0);
            FUN_006ea3d0();
            FUN_00444ad0();
            FUN_00498000();
          }
        }
        else if (wParam != 0x73) {
          *local_40 = 1;
        }
      }
      else {
        switch(param_3) {
        case 0xf:
          *local_40 = 1;
          DefWindowProcW(local_3c,param_3,wParam,uVar3);
          goto LAB_00490c54;
        case 0x10:
          if (uVar3 != 1) {
            FUN_004054c0();
            puVar5 = (undefined4 *)FUN_00891268(0x14);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              *puVar5 = FoxUI::FXUIEvent::vftable;
              puVar5[1] = 0xffffffff;
              puVar5[2] = 0xffffffff;
              puVar5[3] = 0;
              puVar5[4] = 0xf43fe;
            }
            FUN_0058aa50(puVar5);
            *local_40 = 1;
            goto LAB_00490c54;
          }
          break;
        case 0x1c:
          *(WPARAM *)(param_1 + 0xc010) = wParam;
          iVar4 = FUN_0047c300();
          *(undefined1 *)(iVar4 + 0x24) = 1;
          *(bool *)(iVar4 + 0x25) = wParam == 0;
          break;
        case 0x20:
          iVar4 = FUN_0048a240();
          if ((short)uVar3 == 1) {
            *(undefined4 *)(iVar4 + 0x2c) = 1;
            FUN_0048a240();
            iVar4 = FUN_00737450();
            if (iVar4 != 0) {
              *local_40 = 1;
            }
          }
          else {
            *(undefined4 *)(iVar4 + 0x2c) = 0;
          }
          break;
        case 0x24:
          local_2c.left = 0;
          local_2c.top = 0;
          local_2c.right = 0x400;
          local_2c.bottom = 0x2d0;
          AdjustWindowRect(&local_2c,*(DWORD *)(param_1 + 0xc),0);
          *(LONG *)(uVar3 + 0x18) = local_2c.right - local_2c.left;
          *(LONG *)(uVar3 + 0x1c) = local_2c.bottom - local_2c.top;
          *local_40 = 1;
        }
      }
    }
    else {
      switch(param_3) {
      case 0x201:
        *(uint *)(param_1 + 0xc004) = uVar3 & 0xffff;
        *(uint *)(param_1 + 0xc008) = uVar3 >> 0x10;
        SetCapture(local_3c);
        FUN_0048a240();
        FUN_00737a90();
        break;
      case 0x202:
        FUN_0040f060();
        if (*(int *)(DAT_00fba7a4 + 0x7c) == 0) {
          *(uint *)(param_1 + 0xc004) = uVar3 & 0xffff;
          *(uint *)(param_1 + 0xc008) = uVar3 >> 0x10;
        }
        uVar1 = *(undefined4 *)(param_1 + 0xc008);
        uVar2 = *(undefined4 *)(param_1 + 0xc004);
        iVar4 = FUN_00414720();
        if (*(int *)(iVar4 + 0xc) != 0) {
          (**(code **)(**(int **)(iVar4 + 0xc) + 0x24))(uVar2,uVar1,1);
        }
        ReleaseCapture();
        FUN_0048a240();
        ClipCursor((RECT *)0x0);
        break;
      case 0x203:
        *(uint *)(param_1 + 0xc004) = uVar3 & 0xffff;
        *(uint *)(param_1 + 0xc008) = uVar3 >> 0x10;
        break;
      case 0x281:
        DefWindowProcW(local_3c,param_3,wParam,uVar3 & 0xfffffffe);
        *local_40 = 1;
      }
    }
  }
LAB_00490c54:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}


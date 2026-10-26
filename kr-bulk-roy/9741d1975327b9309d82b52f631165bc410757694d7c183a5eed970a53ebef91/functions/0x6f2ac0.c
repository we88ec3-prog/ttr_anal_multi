
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_006f2ac0(int param_1,HWND param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  HIMC__ *pHVar4;
  int iVar5;
  int iVar6;
  HIMC__ HVar7;
  bool bVar8;
  HWND local_13c;
  HIMC__ local_134;
  int local_130;
  HWND__ local_12c;
  LPCSTR local_128;
  uint local_124;
  char local_11d;
  undefined1 local_11c [144];
  int local_8c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_130 = param_1;
  local_13c = param_2;
  if ((*(int *)(param_1 + 0x84) == 0) || (pHVar4 = ImmGetContext(param_2), pHVar4 == (HIMC)0x0)) {
    FUN_00402400(0,0xffffffff);
    goto LAB_006f2f66;
  }
  local_12c.unused = 0;
  if (*(code **)(param_1 + 0x90) == (code *)0x0) {
    local_128 = (LPCSTR)0x0;
    local_124 = 0;
    local_11d = '\0';
    iVar6 = FUN_006f1d70();
    if ((*(code **)(iVar6 + 8) == (code *)0x0) ||
       (HVar7.unused = (**(code **)(iVar6 + 8))(pHVar4), local_134.unused = HVar7.unused,
       (uint *)HVar7.unused == (uint *)0x0)) {
LAB_006f2d4c:
      FUN_00440100(0);
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x84);
      if (uVar1 < 0x4040405) {
        if (uVar1 == 0x4040404) {
LAB_006f2d66:
          uVar1 = *(uint *)(HVar7.unused + 0x124);
          iVar5 = FUN_006f1d70();
          iVar6 = 0;
          if (*(code **)(iVar5 + 0x10) != (code *)0x0) {
            iVar6 = (**(code **)(iVar5 + 0x10))(uVar1);
          }
          iVar6 = *(int *)(iVar6 + 0x18);
          if (iVar6 != 0) {
            local_124 = *(uint *)(iVar6 + 0x9c);
            local_12c.unused = *(uint *)(iVar6 + 0xa0);
            local_128 = (LPCSTR)(iVar6 + 0x38);
            local_11d = '\x01';
          }
        }
        else if (uVar1 < 0x4020805) {
          if (uVar1 == 0x4020804) {
            local_11c._128_2_ = L'\x94';
            local_11c._130_2_ = L'\0';
            GetVersionExA((LPOSVERSIONINFOA)(local_11c + 0x80));
            uVar1 = *(uint *)(HVar7.unused + 0x124);
            bVar8 = local_8c == 2;
            iVar5 = FUN_006f1d70();
            iVar6 = 0;
            if (*(code **)(iVar5 + 0x10) != (code *)0x0) {
              iVar6 = (**(code **)(iVar5 + 0x10))(uVar1);
            }
            iVar6 = *(int *)(iVar6 + 0x20);
            param_1 = local_130;
            HVar7.unused = local_134.unused;
            if (iVar6 != 0) {
              local_124 = *(uint *)(iVar6 + (bVar8 + 5) * 0x10);
              local_12c.unused = *(uint *)(iVar6 + 0x44 + (bVar8 + 1) * 0x10);
              local_128 = (LPCSTR)(iVar6 + 0x40);
              local_11d = local_8c == 2;
            }
          }
          else if (uVar1 == 0x4010804) {
            uVar1 = *(uint *)(param_1 + 0x88);
            uVar2 = *(uint *)(HVar7.unused + 0x124);
            iVar5 = FUN_006f1d70();
            iVar6 = 0;
            if (*(code **)(iVar5 + 0x10) != (code *)0x0) {
              iVar6 = (**(code **)(iVar5 + 0x10))(uVar2);
            }
            iVar6 = *(int *)(iVar6 + 0x20 + (uint)(uVar1 < 2) * -4);
            HVar7.unused = local_134.unused;
            if (iVar6 != 0) {
              local_124 = *(uint *)(iVar6 + 0x9c);
              local_12c.unused = *(uint *)(iVar6 + 0xa0);
              if (local_124 <= *(uint *)(iVar6 + 0xa0)) {
                local_12c.unused = local_124;
              }
              local_128 = (LPCSTR)(iVar6 + 0x38);
              local_11d = '\x01';
            }
          }
          else {
            if (uVar1 == 0x4020404) goto LAB_006f2d66;
            local_128 = (LPCSTR)0x0;
            local_124 = 0;
          }
        }
        else {
          if (uVar1 == 0x4030404) goto LAB_006f2d66;
LAB_006f2e1f:
          local_128 = (LPCSTR)0x0;
          local_124 = 0;
        }
      }
      else {
        if (uVar1 < 0x5020405) {
          if (uVar1 != 0x5020404) {
            if (uVar1 == 0x5000404) {
              uVar1 = *(uint *)(HVar7.unused + 0x124);
              iVar5 = FUN_006f1d70();
              iVar6 = 0;
              if (*(code **)(iVar5 + 0x10) != (code *)0x0) {
                iVar6 = (**(code **)(iVar5 + 0x10))(uVar1);
              }
              if ((*(int *)(iVar6 + 0xc) != 0) &&
                 (iVar6 = *(int *)(*(int *)(iVar6 + 0xc) + 0x20), iVar6 != 0)) {
                local_124 = *(uint *)(iVar6 + 0x50);
                local_12c.unused = *(uint *)(iVar6 + 0x54);
                local_128 = (LPCSTR)(iVar6 + 0x40);
                local_11d = '\0';
              }
              goto LAB_006f2d23;
            }
            bVar8 = uVar1 == 0x5010404;
            goto LAB_006f2e1d;
          }
        }
        else {
          bVar8 = uVar1 == 0x5030804;
LAB_006f2e1d:
          if (!bVar8) goto LAB_006f2e1f;
        }
        local_11c._0_4_ = 0x114;
        GetVersionExW((LPOSVERSIONINFOW)local_11c);
        if (((*(int *)(param_1 + 0x84) != 0x5030804) || (local_11c._4_4_ != 5)) ||
           (local_11c._8_4_ != 2)) {
          uVar1 = *(uint *)(HVar7.unused + 0x124);
          iVar5 = FUN_006f1d70();
          iVar6 = 0;
          if (*(code **)(iVar5 + 0x10) != (code *)0x0) {
            iVar6 = (**(code **)(iVar5 + 0x10))(uVar1);
          }
          if ((*(int *)(iVar6 + 4) != 0) &&
             (iVar6 = *(int *)(*(int *)(iVar6 + 4) + 0x18), iVar6 != 0)) {
            local_124 = *(uint *)(iVar6 + 0x60);
            local_12c.unused = *(uint *)(iVar6 + 100);
            local_128 = (LPCSTR)(iVar6 + 0x40);
            local_11d = '\x01';
          }
        }
      }
LAB_006f2d23:
      uVar1 = *(uint *)(HVar7.unused + 0x124);
      iVar6 = FUN_006f1d70();
      if (*(code **)(iVar6 + 0x14) != (code *)0x0) {
        (**(code **)(iVar6 + 0x14))(uVar1);
      }
      if (local_124 == 0) goto LAB_006f2d4c;
      if (local_11d == '\0') {
        iVar6 = MultiByteToWideChar((uint)*(ushort *)(param_1 + 0x70),0,local_128,local_124,
                                    (LPWSTR)0x0,0);
        MultiByteToWideChar((uint)*(ushort *)(local_130 + 0x70),0,local_128,local_124,
                            (LPWSTR)&stack0xfffffeb8,iVar6);
        FUN_00402160(&stack0xfffffeb8,iVar6);
        param_1 = local_130;
      }
      else {
        FUN_00402160(local_128,local_124);
      }
    }
    iVar6 = FUN_006f1d70();
    if (*(code **)(iVar6 + 0xc) != (code *)0x0) {
      (**(code **)(iVar6 + 0xc))(pHVar4);
    }
    cVar3 = FUN_006f2960();
    *(bool *)(param_1 + 0x7d) = cVar3 == '\0';
  }
  else {
    iVar5 = (**(code **)(param_1 + 0x90))(pHVar4,0,0,&local_12c,&local_134,&local_124);
    iVar6 = local_130;
    if (iVar5 == 0) {
      FUN_00440100(0);
      iVar6 = param_1;
    }
    else {
      local_134.unused = (int)&local_124;
      pHVar4 = &local_134;
      local_13c = &local_12c;
      (**(code **)(local_130 + 0x90))();
      FUN_006f3180(&local_130,(int)&local_130 + iVar5 * 2);
    }
    *(bool *)(iVar6 + 0x7d) = (uint *)local_134.unused != (uint *)0x0;
    ImmReleaseContext(local_13c,pHVar4);
  }
  ImmReleaseContext(local_13c,pHVar4);
LAB_006f2f66:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


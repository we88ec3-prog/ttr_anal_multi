
void FUN_006e8360(int param_1,byte param_2,int param_3)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  wchar_t *pwVar8;
  WCHAR local_410 [511];
  undefined2 local_12;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar4 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar4 + 0x2fe);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 != '\0') goto LAB_006e87d6;
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar4 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  psVar7 = (short *)(iVar4 + 0x94c);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (param_1 == 1) {
    if (DAT_00fba7cc == 0) {
      iVar4 = FUN_00891268(0x1380);
      if (iVar4 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar4 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    puVar3 = *(undefined4 **)(iVar4 + 0xc);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    FUN_006e3660(0);
    iVar4 = FUN_006ec8b0(*puVar3,puVar3[2],puVar3[6],puVar3[0xc]);
    if (iVar4 == 0) {
      MultiByteToWideChar(0,0,(LPCSTR)(param_3 + 0x200),-1,local_410,0x200);
      local_12 = 0;
      iVar4 = 0x100;
      psVar6 = psVar7;
      do {
        psVar5 = psVar6;
        if ((iVar4 == -0x7ffffefe) ||
           (sVar2 = *(short *)(((int)local_410 - (int)psVar7) + (int)psVar5), sVar2 == 0)) {
          if (iVar4 == 0) {
            psVar5 = psVar5 + -1;
          }
          *psVar5 = 0;
          goto LAB_006e84de;
        }
        *psVar5 = sVar2;
        iVar4 = iVar4 + -1;
        psVar6 = psVar5 + 1;
      } while (iVar4 != 0);
      *psVar5 = 0;
    }
    else {
      FUN_006eadb0(*(int *)(iVar4 + 0x50) + 0x450,0x7ffffffe);
    }
LAB_006e84de:
    iVar4 = 0x100;
    psVar6 = psVar7;
    do {
      if (*psVar6 == 0) {
        if (iVar4 != 0) {
          pwVar8 = L"(HAL";
LAB_006e85cc:
          FUN_006eadb0(pwVar8,0x7fffffff);
        }
        break;
      }
      psVar6 = psVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else if (param_1 == 2) {
    iVar4 = 0x100;
    psVar6 = psVar7;
    do {
      if (*psVar6 == 0) {
        if (iVar4 != 0) {
          pwVar8 = L"(REF";
          goto LAB_006e85cc;
        }
        break;
      }
      psVar6 = psVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else if (param_1 == 3) {
    iVar4 = 0x100;
    psVar6 = psVar7;
    do {
      if (*psVar6 == 0) {
        if (iVar4 != 0) {
          pwVar8 = L"(SW";
          goto LAB_006e85cc;
        }
        break;
      }
      psVar6 = psVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (((param_2 & 0x40) == 0) || ((param_2 & 0x10) == 0)) {
    iVar4 = 0x100;
    if ((param_2 & 0x40) == 0) {
      if ((char)param_2 < '\0') {
        if (param_1 == 1) {
          while (*psVar7 != 0) {
            psVar7 = psVar7 + 1;
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) {
              __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
              return;
            }
          }
          if (iVar4 == 0) goto LAB_006e87d6;
          pwVar8 = L", mixed vp)";
        }
        else {
          while (*psVar7 != 0) {
            psVar7 = psVar7 + 1;
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) {
              __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
              return;
            }
          }
          if (iVar4 == 0) goto LAB_006e87d6;
          pwVar8 = L", simulated mixed vp)";
        }
      }
      else if ((param_2 & 0x20) == 0) {
        while (*psVar7 != 0) {
          psVar7 = psVar7 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
            return;
          }
        }
        if (iVar4 == 0) goto LAB_006e87d6;
        pwVar8 = L")";
      }
      else {
        while (*psVar7 != 0) {
          psVar7 = psVar7 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
            return;
          }
        }
        if (iVar4 == 0) goto LAB_006e87d6;
        pwVar8 = L", swvp)";
      }
    }
    else if (param_1 == 1) {
      while (*psVar7 != 0) {
        psVar7 = psVar7 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      if (iVar4 == 0) goto LAB_006e87d6;
      pwVar8 = L", hwvp)";
    }
    else {
      while (*psVar7 != 0) {
        psVar7 = psVar7 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      if (iVar4 == 0) goto LAB_006e87d6;
      pwVar8 = L", simulated hwvp)";
    }
  }
  else {
    iVar4 = 0x100;
    if (param_1 == 1) {
      while (*psVar7 != 0) {
        psVar7 = psVar7 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      if (iVar4 == 0) goto LAB_006e87d6;
      pwVar8 = L", pure hwvp)";
    }
    else {
      while (*psVar7 != 0) {
        psVar7 = psVar7 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      if (iVar4 == 0) goto LAB_006e87d6;
      pwVar8 = L", simulated pure hwvp)";
    }
  }
  FUN_006eadb0(pwVar8,0x7fffffff);
LAB_006e87d6:
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_00896286(int param_1)

{
  int *piVar1;
  errno_t eVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  tm *ptVar5;
  long local_38;
  long local_34;
  uint local_30;
  tm local_2c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_38 = 0;
  local_34 = 0;
  if (in_ECX == (int *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    goto LAB_0089634c;
  }
  local_30 = in_ECX[5];
  if (local_30 - 0x45 < 0x47) {
    iVar4 = in_ECX[4];
    if ((iVar4 < 0) || (0xb < iVar4)) {
      iVar3 = iVar4 % 0xc;
      local_30 = local_30 + iVar4 / 0xc;
      in_ECX[4] = iVar3;
      if (iVar3 < 0) {
        local_30 = local_30 - 1;
        in_ECX[4] = iVar3 + 0xc;
      }
      if (0x46 < local_30 - 0x45) goto LAB_0089633d;
    }
    iVar4 = (&DAT_00d620d4)[in_ECX[4]];
    if (((local_30 & 3) == 0) && (1 < in_ECX[4])) {
      iVar4 = iVar4 + 1;
    }
    iVar4 = local_30 * 0x16d + -0x63df + ((int)(local_30 - 1) >> 2) + iVar4;
    iVar3 = in_ECX[3];
    local_30 = iVar4 + iVar3;
    if (iVar4 < 0) {
      if ((-1 < iVar3) || ((int)local_30 < 0)) goto LAB_00896362;
    }
    else if ((iVar3 < 0) || (-1 < (int)local_30)) {
LAB_00896362:
      iVar4 = local_30 * 0x18;
      if (local_30 == 0 || iVar4 / (int)local_30 == 0x18) {
        iVar3 = in_ECX[2];
        local_30 = iVar3 + iVar4;
        if (iVar4 < 0) {
          if ((-1 < iVar3) || ((int)local_30 < 0)) goto LAB_008963a1;
        }
        else if ((iVar3 < 0) || (-1 < (int)local_30)) {
LAB_008963a1:
          iVar4 = local_30 * 0x3c;
          if (local_30 == 0 || iVar4 / (int)local_30 == 0x3c) {
            iVar3 = in_ECX[1];
            local_30 = iVar3 + iVar4;
            if (iVar4 < 0) {
              if ((-1 < iVar3) || ((int)local_30 < 0)) goto LAB_008963ec;
            }
            else if ((iVar3 < 0) || (-1 < (int)local_30)) {
LAB_008963ec:
              iVar4 = local_30 * 0x3c;
              if (local_30 == 0 || iVar4 / (int)local_30 == 0x3c) {
                iVar3 = *in_ECX;
                local_30 = iVar3 + iVar4;
                if (iVar4 < 0) {
                  if ((-1 < iVar3) || ((int)local_30 < 0)) goto LAB_00896436;
                }
                else if ((iVar3 < 0) || (-1 < (int)local_30)) {
LAB_00896436:
                  if (param_1 == 0) {
                    iVar4 = __gmtime32_s(&local_2c,(__time32_t *)&local_30);
LAB_008964b3:
                    if (iVar4 == 0) {
LAB_008964bd:
                      ptVar5 = &local_2c;
                      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
                        *in_ECX = ptVar5->tm_sec;
                        ptVar5 = (tm *)&ptVar5->tm_min;
                        in_ECX = in_ECX + 1;
                      }
                      goto LAB_0089634c;
                    }
                  }
                  else {
                    ___tzset();
                    eVar2 = FID_conflict___get_dstbias(&local_38);
                    if ((eVar2 != 0) || (eVar2 = FID_conflict___get_dstbias(&local_34), eVar2 != 0))
                    {
                    /* WARNING: Subroutine does not return */
                      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                    }
                    local_30 = local_30 + local_34;
                    iVar4 = FUN_00897163(&local_2c,&local_30);
                    if (iVar4 == 0) {
                      if ((0 < in_ECX[8]) || ((in_ECX[8] < 0 && (0 < local_2c.tm_isdst)))) {
                        local_30 = local_30 + local_38;
                        iVar4 = FUN_00897163(&local_2c,&local_30);
                        goto LAB_008964b3;
                      }
                      goto LAB_008964bd;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0089633d:
  piVar1 = __errno();
  *piVar1 = 0x16;
LAB_0089634c:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


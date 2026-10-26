
/* WARNING: Type propagation algorithm not settling */

void FUN_004d5ae0(int param_1,undefined4 param_2,undefined4 param_3)

{
  wchar_t wVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  wchar_t *pwVar6;
  wchar_t *******pppppppwVar7;
  int iVar8;
  int *unaff_FS_OFFSET;
  bool bVar9;
  int *piVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  int local_35c;
  int local_358;
  float local_354;
  undefined2 local_350;
  int local_34e;
  undefined1 local_34a;
  wchar_t local_349 [52];
  wchar_t *******local_2e0 [4];
  undefined4 local_2d0;
  uint local_2cc;
  undefined1 local_2c4 [520];
  undefined1 local_bc [128];
  undefined1 local_3c [12];
  undefined4 local_30 [5];
  uint local_1c;
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009395bd;
  local_10 = *unaff_FS_OFFSET;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_350 = 0x11;
  local_358 = param_1;
  local_34e = 0;
  local_34a = (undefined1)param_2;
  local_2cc = 7;
  local_2d0 = 0;
  local_2e0[0] = (wchar_t *******)((uint)local_2e0[0] & 0xffff0000);
  local_8 = 0;
  uStack_7 = 0;
  FUN_004d7420(param_3,local_2e0,local_14);
  pppppppwVar7 = local_2e0[0];
  if (local_2cc < 8) {
    pppppppwVar7 = (wchar_t *******)local_2e0;
  }
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 1;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_8 = 0;
  }
  iVar5 = FUN_0049d770(&DAT_00fab104,pppppppwVar7);
  if (iVar5 == 0) {
    pppppppwVar7 = local_2e0[0];
    if (local_2cc < 8) {
      pppppppwVar7 = (wchar_t *******)local_2e0;
    }
    pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/FreeCam");
    if (pwVar6 == (wchar_t *)0x0) {
      pppppppwVar7 = local_2e0[0];
      if (local_2cc < 8) {
        pppppppwVar7 = (wchar_t *******)local_2e0;
      }
      pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/프리로드");
      if (pwVar6 == (wchar_t *)0x0) {
        pppppppwVar7 = local_2e0[0];
        if (local_2cc < 8) {
          pppppppwVar7 = (wchar_t *******)local_2e0;
        }
        pwVar6 = L"/쿨타임리셋";
        do {
          wVar1 = *(wchar_t *)pppppppwVar7;
          bVar9 = (ushort)wVar1 < (ushort)*pwVar6;
          if (wVar1 != *pwVar6) {
LAB_004d5de6:
            iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_004d5deb;
          }
          if (wVar1 == L'\0') break;
          wVar1 = *(wchar_t *)((int)pppppppwVar7 + 2);
          bVar9 = (ushort)wVar1 < (ushort)pwVar6[1];
          if (wVar1 != pwVar6[1]) goto LAB_004d5de6;
          pppppppwVar7 = pppppppwVar7 + 1;
          pwVar6 = pwVar6 + 2;
        } while (wVar1 != L'\0');
        iVar5 = 0;
LAB_004d5deb:
        if (iVar5 == 0) {
          iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
          if (iVar5 != 0) {
            FUN_0040f060();
            iVar5 = FUN_004dfad0();
            if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
              FUN_0040f060();
              FUN_00597b70();
            }
          }
        }
        else {
          pppppppwVar7 = local_2e0[0];
          if (local_2cc < 8) {
            pppppppwVar7 = (wchar_t *******)local_2e0;
          }
          pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/reqavf");
          if (pwVar6 == (wchar_t *)0x0) {
            pppppppwVar7 = local_2e0[0];
            if (local_2cc < 8) {
              pppppppwVar7 = (wchar_t *******)local_2e0;
            }
            pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/nc");
            if (pwVar6 == (wchar_t *)0x0) {
              pppppppwVar7 = local_2e0[0];
              if (local_2cc < 8) {
                pppppppwVar7 = (wchar_t *******)local_2e0;
              }
              pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/대전제의");
              if (pwVar6 == (wchar_t *)0x0) {
                pppppppwVar7 = local_2e0[0];
                if (local_2cc < 8) {
                  pppppppwVar7 = (wchar_t *******)local_2e0;
                }
                pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/앉기");
                if (pwVar6 != (wchar_t *)0x0) {
                  FUN_00444960();
                  local_35c = 1;
                  FUN_0041e560();
                  FUN_004fa440();
                  goto LAB_004d657c;
                }
                pppppppwVar7 = local_2e0[0];
                if (local_2cc < 8) {
                  pppppppwVar7 = (wchar_t *******)local_2e0;
                }
                pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/시야표시");
                if (pwVar6 == (wchar_t *)0x0) {
                  pppppppwVar7 = local_2e0[0];
                  if (local_2cc < 8) {
                    pppppppwVar7 = (wchar_t *******)local_2e0;
                  }
                  pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/chatuid");
                  if (pwVar6 == (wchar_t *)0x0) {
                    pppppppwVar7 = local_2e0[0];
                    if (local_2cc < 8) {
                      pppppppwVar7 = (wchar_t *******)local_2e0;
                    }
                    pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/a");
                    if (pwVar6 == (wchar_t *)0x0) {
                      pppppppwVar7 = local_2e0[0];
                      if (local_2cc < 8) {
                        pppppppwVar7 = (wchar_t *******)local_2e0;
                      }
                      pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/A");
                      if (pwVar6 == (wchar_t *)0x0) {
                        pppppppwVar7 = local_2e0[0];
                        if (local_2cc < 8) {
                          pppppppwVar7 = (wchar_t *******)local_2e0;
                        }
                        pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/b");
                        if (pwVar6 == (wchar_t *)0x0) {
                          pppppppwVar7 = local_2e0[0];
                          if (local_2cc < 8) {
                            pppppppwVar7 = (wchar_t *******)local_2e0;
                          }
                          pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/B");
                          if (pwVar6 == (wchar_t *)0x0) {
                            pppppppwVar7 = local_2e0[0];
                            if (local_2cc < 8) {
                              pppppppwVar7 = (wchar_t *******)local_2e0;
                            }
                            pwVar6 = _wcsstr((wchar_t *)pppppppwVar7,L"/c");
                            if (pwVar6 == (wchar_t *)0x0) {
                              pppppppwVar7 = local_2e0[0];
                              if (local_2cc < 8) {
                                pppppppwVar7 = (wchar_t *******)local_2e0;
                              }
                              _wcsstr((wchar_t *)pppppppwVar7,L"/C");
                            }
                          }
                        }
                      }
                    }
                  }
                  else {
                    iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
                    if (iVar5 != 0) {
                      FUN_0040f060();
                      iVar5 = FUN_004dfad0();
                      if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
                        *(uint *)(local_358 + 0x124) = (uint)(*(int *)(local_358 + 0x124) == 0);
                        FUN_004d6c90();
                        FUN_004fa440();
                        goto LAB_004d657c;
                      }
                    }
                  }
                }
                else {
                  iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
                  if (iVar5 != 0) {
                    FUN_0040f060();
                    iVar5 = FUN_004dfad0();
                    if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
                      local_354 = 0.0;
                      pppppppwVar7 = local_2e0[0];
                      if (local_2cc < 8) {
                        pppppppwVar7 = (wchar_t *******)local_2e0;
                      }
                      iVar5 = FID_conflict__swscanf
                                        ((wchar_t *)pppppppwVar7,L"%s %f",local_bc,0x40,&local_354);
                      piVar10 = DAT_00fba7a4;
                      if ((iVar5 == 2) && (DAT_00fba7a4[0x21] = (int)local_354, 1000.0 < local_354))
                      {
                        piVar10[0x21] = 0x447a0000;
                      }
                    }
                  }
                }
              }
              else {
                iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
                if (iVar5 != 0) {
                  FUN_0040f060();
                  iVar5 = FUN_004dfad0();
                  if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
                    pppppppwVar7 = local_2e0[0];
                    if (local_2cc < 8) {
                      pppppppwVar7 = (wchar_t *******)local_2e0;
                    }
                    FID_conflict__swscanf
                              ((wchar_t *)pppppppwVar7,L"%s %s",local_2c4,0x104,local_3c,0x14);
                    puVar11 = local_3c;
                    piVar10 = &local_35c;
                    FUN_00425330(piVar10,puVar11);
                    cVar4 = FUN_004f6d20(piVar10,puVar11);
                    if (cVar4 != '\0') {
                      FUN_0040f060();
                      iVar5 = FUN_004dfad0();
                      sVar2 = *(short *)(iVar5 + 0x14);
                      if (sVar2 != 0) {
                        FUN_00414680();
                        FUN_004a4240(sVar2);
                        FUN_004fa440();
                        goto LAB_004d657c;
                      }
                    }
                    goto LAB_004d5f04;
                  }
                }
              }
            }
            else {
              iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
              if (iVar5 != 0) {
                FUN_0040f060();
                iVar5 = FUN_004dfad0();
                if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
                  pppppppwVar7 = local_2e0[0];
                  if (local_2cc < 8) {
                    pppppppwVar7 = (wchar_t *******)local_2e0;
                  }
                  FID_conflict__swscanf((wchar_t *)pppppppwVar7,L"%s %d",local_2c4,0x104,&local_35c)
                  ;
                  FUN_00414680();
                  FUN_004a4200(local_35c);
                  FUN_004fa440();
                  goto LAB_004d657c;
                }
              }
            }
          }
          else {
            iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
            if (iVar5 != 0) {
              FUN_0040f060();
              iVar5 = FUN_004dfad0();
              if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
                pppppppwVar7 = local_2e0[0];
                if (local_2cc < 8) {
                  pppppppwVar7 = (wchar_t *******)local_2e0;
                }
                FID_conflict__swscanf
                          ((wchar_t *)pppppppwVar7,L"%s %d %d %d",local_2c4,0x104,&local_35c,
                           &local_358,&local_354);
                FUN_00414680();
                FUN_004a4620(local_354);
LAB_004d5f04:
                FUN_004fa440();
                goto LAB_004d657c;
              }
            }
          }
        }
      }
      else {
        local_354 = 0.0;
        pppppppwVar7 = local_2e0[0];
        if (local_2cc < 8) {
          pppppppwVar7 = (wchar_t *******)local_2e0;
        }
        iVar5 = FID_conflict__swscanf((wchar_t *)pppppppwVar7,L"%s %d",local_bc,0x40,&local_354);
        if (iVar5 == 2) {
          FUN_0047ae40();
          FUN_00541610(local_354);
        }
      }
      iVar5 = local_35c;
      switch(param_2) {
      case 0:
        local_34a = 0;
        break;
      case 1:
        if (local_35c != 0) {
          iVar8 = local_35c;
          FUN_00425330(local_35c);
          iVar8 = FUN_004f6dc0(iVar8);
          if (iVar8 == -1) {
            local_34a = 1;
            pppppppwVar7 = local_2e0[0];
            if (local_2cc < 8) {
              pppppppwVar7 = (wchar_t *******)local_2e0;
            }
            FUN_004d8300(L"#%s %s",iVar5,pppppppwVar7);
            FUN_0041f490(local_2e0);
          }
          else {
            local_34a = 2;
            local_34e = iVar8;
          }
        }
        break;
      case 2:
        local_34a = 3;
        break;
      case 3:
        local_34a = 5;
      }
      bVar9 = false;
      pppppppwVar7 = local_2e0[0];
      if (local_2cc < 8) {
        pppppppwVar7 = (wchar_t *******)local_2e0;
      }
      iVar5 = _wcsncmp((wchar_t *)pppppppwVar7,L"//",2);
      if ((iVar5 == 0) && (iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar5 != 0)) {
        FUN_0040f060();
        iVar5 = FUN_004dfad0();
        if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
          bVar9 = true;
        }
      }
      if ((DAT_00fb75c0 & 1) == 0) {
        DAT_00fb75c0 = DAT_00fb75c0 | 1;
        local_8 = 9;
        FUN_0081e5f0();
        _atexit((_func_4879 *)&LAB_00bcd250);
        local_8 = 0;
      }
      iVar5 = FUN_0081ec70(0xf1);
      if ((iVar5 == 0) && (!bVar9)) {
        uVar12 = 0x1b0;
        FUN_005854b0(0x1b0);
        uVar12 = FUN_00585330(uVar12);
        FUN_00402250(uVar12);
        local_8 = 10;
        FUN_004d6b30(local_30);
        FUN_004fa440();
        FUN_004fa440();
        goto LAB_004d657c;
      }
      pppppppwVar7 = local_2e0[0];
      if (local_2cc < 8) {
        pppppppwVar7 = (wchar_t *******)local_2e0;
      }
      _wcscpy_s(local_349,0x33,(wchar_t *)pppppppwVar7);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_350,0x6d);
      }
    }
    else {
      FUN_0040f060();
      if (DAT_00fba7a4[0x1e] == 0) {
        iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
        if (iVar5 != 0) {
          FUN_0040f060();
          iVar5 = FUN_004dfad0();
          if ((iVar5 != 0) && (4 < *(byte *)(iVar5 + 0x20))) {
            FUN_0040f060();
            DAT_00fba7a4[0x1e] = 1;
            FUN_0054c770(1);
            FUN_00402250(L"FreeCamera Mode Activated");
            local_8 = 2;
            FUN_004d6b30(local_30);
            FUN_004fa440();
          }
        }
      }
      else {
        FUN_0040f060();
        uVar3 = DAT_00fb79e8 & 1;
        DAT_00fba7a4[0x1e] = 0;
        DAT_00fbab34 = 0;
        DAT_00fbab38 = 0;
        if (uVar3 == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 7;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0;
        }
        iVar5 = DAT_00fb76e8;
        *(undefined4 *)(DAT_00fb76e8 + 0xd8) = *(undefined4 *)(DAT_00fb76e8 + 0xd4);
        *(undefined4 *)(iVar5 + 0xb0) = 1;
        FUN_00402250(L"FreeCamera Mode Deactivated");
        local_8 = 8;
        FUN_004d6b30(local_30);
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
    }
  }
  if (7 < local_2cc) {
    FUN_0089120c(local_2e0[0]);
  }
LAB_004d657c:
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



/* WARNING: Removing unreachable block (ram,0x007a59e7) */

void FUN_007a57c0(void)

{
  LONG *pLVar1;
  _RTL_CRITICAL_SECTION_DEBUG *p_Var2;
  _RTL_CRITICAL_SECTION_DEBUG *p_Var3;
  int iVar4;
  _RTL_CRITICAL_SECTION *p_Var5;
  LPCRITICAL_SECTION p_Var6;
  char cVar7;
  int *piVar8;
  int in_ECX;
  int *piVar9;
  uint uVar10;
  PRTL_CRITICAL_SECTION_DEBUG p_Stack_44;
  _RTL_CRITICAL_SECTION_DEBUG _Stack_24;
  
  _Stack_24.Flags = 0xffffffff;
  _Stack_24.ContentionCount = (DWORD)&LAB_009391a9;
  _Stack_24.EntryCount = (DWORD)ExceptionList;
  ExceptionList = &_Stack_24.EntryCount;
  if (*(int **)(in_ECX + 0x118) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x118) + 8))();
    *(undefined4 *)(in_ECX + 0x118) = 0;
  }
  if (*(int *)(in_ECX + 0x1c) == 1) {
    p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a581c;
    _Stack_24.ProcessLocksList.Flink = (_LIST_ENTRY *)FUN_00891268();
    _Stack_24.Flags = 0;
    if (_Stack_24.ProcessLocksList.Flink != (_LIST_ENTRY *)0x0) {
      p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5831;
      FUN_007a5680();
    }
    p_Stack_44 = &_Stack_24;
    _Stack_24.Flags = 0xffffffff;
    _Stack_24._0_4_ = (int *)0x0;
    _Stack_24.CriticalSection = (_RTL_CRITICAL_SECTION *)0x0;
    FUN_007aa780();
    piVar9 = (int *)_Stack_24._0_4_;
    _Stack_24.Flags = 1;
    *(int *)_Stack_24._0_4_ = *(int *)(in_ECX + 0x10);
    p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5869;
    FUN_007a5730();
    *(int *)((undefined4)piVar9 + 1) = *(int *)(in_ECX + 0x14);
    if ((int *)((undefined4)piVar9 + 10) != (int *)(in_ECX + 100)) {
      p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)**(undefined4 **)((undefined4)piVar9 + 0xb);
      FUN_006d7120();
      p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5896;
      FUN_007aa150();
      piVar9 = (int *)_Stack_24._0_4_;
    }
    _Stack_24.ProcessLocksList.Flink = (_LIST_ENTRY *)&p_Stack_44;
    p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
    p_Var6 = (LPCRITICAL_SECTION)&p_Stack_44;
    if ((_Stack_24.CriticalSection != (_RTL_CRITICAL_SECTION *)0x0) &&
       (cVar7 = FUN_0047c250(), p_Var6 = (LPCRITICAL_SECTION)_Stack_24.ProcessLocksList.Flink,
       cVar7 != '\0')) {
      FUN_007a31c0(piVar9,_Stack_24.CriticalSection);
      p_Var6 = (LPCRITICAL_SECTION)_Stack_24.ProcessLocksList.Flink;
    }
    _Stack_24.ProcessLocksList.Flink = (_LIST_ENTRY *)p_Var6;
    uVar10 = _Stack_24.Flags >> 8;
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      _Stack_24.Flags._0_1_ = 3;
      FUN_0079cf40();
      _atexit((_func_4879 *)&LAB_00bcdb80);
      uVar10 = (uint)_Stack_24.Flags._1_3_;
    }
    _Stack_24.Flags._1_3_ = (uint3)uVar10;
    _Stack_24.Flags = CONCAT31(_Stack_24.Flags._1_3_,1);
    FUN_0079de00();
    *(undefined4 *)(in_ECX + 0x14) = 0;
    FUN_00597b70();
    if (*(int **)(in_ECX + 0x98) != (int *)0x0) {
      piVar9 = (int *)(**(int **)(in_ECX + 0x98) + 0x2c);
      *piVar9 = *piVar9 + -1;
      p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5934;
      FUN_0089120c();
      *(undefined4 *)(in_ECX + 0x98) = 0;
    }
    p_Var5 = _Stack_24.CriticalSection;
    _Stack_24.Flags = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined1 *)(in_ECX + 0x20) = 1;
    if (_Stack_24.CriticalSection != (_RTL_CRITICAL_SECTION *)0x0) {
      LOCK();
      iVar4 = (_Stack_24.CriticalSection)->LockCount + -1;
      (_Stack_24.CriticalSection)->LockCount = iVar4;
      UNLOCK();
      if (iVar4 == 0) {
        (**(code **)(_Stack_24.CriticalSection)->DebugInfo)();
        pLVar1 = &p_Var5->RecursionCount;
        LOCK();
        iVar4 = *pLVar1 + -1;
        *pLVar1 = iVar4;
        UNLOCK();
        if (iVar4 == 0) {
          (*(code *)p_Var5->DebugInfo->CriticalSection)();
        }
      }
    }
  }
  uVar10 = 0;
  if (*(int *)(in_ECX + 0x148) - *(int *)(in_ECX + 0x144) >> 3 != 0) {
    do {
      if (*(int *)(*(int *)(in_ECX + 0x144) + 4 + uVar10 * 8) != 0) {
        p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a59a6;
        FUN_007d8890();
        p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a59ac;
        FUN_0089120c();
        *(undefined4 *)(*(int *)(in_ECX + 0x144) + 4 + uVar10 * 8) = 0;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(*(int *)(in_ECX + 0x148) - *(int *)(in_ECX + 0x144) >> 3));
  }
  if (*(int *)(in_ECX + 0x144) != *(int *)(in_ECX + 0x148)) {
    *(int *)(in_ECX + 0x148) = *(int *)(in_ECX + 0x144);
  }
  if (*(int *)(in_ECX + 0x100) != 0) {
    p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5a11;
    FUN_007be0f0();
  }
  piVar9 = (int *)**(int **)(in_ECX + 0x104);
  if (piVar9 != *(int **)(in_ECX + 0x104)) {
    do {
      piVar8 = (int *)piVar9[2];
      if (piVar8 != (int *)0x0) {
        *(int *)(*piVar8 + 0x60) = *(int *)(*piVar8 + 0x60) + -1;
        if ((piVar8[0x1d] == 0) || (piVar8[0x1e] == 0)) {
          if (0 < piVar8[0x1d]) {
            p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5aed;
            FUN_007be0f0();
          }
        }
        else {
          iVar4 = *piVar8;
          _Stack_24._0_4_ = piVar8;
          if (0 < *(int *)(iVar4 + 0x44)) {
            _Stack_24.ProcessLocksList.Flink = (_LIST_ENTRY *)(iVar4 + 100);
            p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5a6e;
            EnterCriticalSection((LPCRITICAL_SECTION)_Stack_24.ProcessLocksList.Flink);
            p_Var2 = *(_RTL_CRITICAL_SECTION_DEBUG **)(iVar4 + 0x80);
            if (&_Stack_24 < p_Var2) {
              p_Var3 = *(_RTL_CRITICAL_SECTION_DEBUG **)(iVar4 + 0x7c);
              if (&_Stack_24 < p_Var3) goto LAB_007a5ab2;
              if (p_Var2 == *(_RTL_CRITICAL_SECTION_DEBUG **)(iVar4 + 0x84)) {
                FUN_00797930();
              }
              if (*(undefined4 **)(iVar4 + 0x80) != (undefined4 *)0x0) {
                **(undefined4 **)(iVar4 + 0x80) =
                     *(undefined4 *)
                      (*(int *)(iVar4 + 0x7c) + ((int)&_Stack_24 - (int)p_Var3 >> 2) * 4);
              }
            }
            else {
LAB_007a5ab2:
              if (p_Var2 == *(_RTL_CRITICAL_SECTION_DEBUG **)(iVar4 + 0x84)) {
                FUN_00797930();
              }
              if (*(undefined4 **)(iVar4 + 0x80) != (undefined4 *)0x0) {
                **(undefined4 **)(iVar4 + 0x80) = piVar8;
              }
            }
            *(int *)(iVar4 + 0x80) = *(int *)(iVar4 + 0x80) + 4;
            p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5ae0;
            LeaveCriticalSection((LPCRITICAL_SECTION)_Stack_24.ProcessLocksList.Flink);
            goto LAB_007a5b01;
          }
        }
        FUN_007bd850();
        p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5afa;
        FUN_0089120c();
      }
LAB_007a5b01:
      piVar8 = (int *)piVar9[3];
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 0x10))();
        (**(code **)(*piVar8 + 8))();
      }
      piVar8 = (int *)*piVar9;
      if (piVar9 != *(int **)(in_ECX + 0x104)) {
        *(int **)piVar9[1] = piVar8;
        *(int *)(*piVar9 + 4) = piVar9[1];
        p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5b37;
        FUN_0089120c();
        *(int *)(in_ECX + 0x108) = *(int *)(in_ECX + 0x108) + -1;
      }
      piVar9 = piVar8;
    } while (piVar8 != (int *)*(int *)(in_ECX + 0x104));
  }
  piVar9 = *(int **)(in_ECX + 0x104);
  piVar8 = (int *)*piVar9;
  *piVar9 = (int)piVar9;
  *(int *)(*(int *)(in_ECX + 0x104) + 4) = *(int *)(in_ECX + 0x104);
  *(undefined4 *)(in_ECX + 0x108) = 0;
  if (piVar8 != *(int **)(in_ECX + 0x104)) {
    do {
      piVar8 = (int *)*piVar8;
      p_Stack_44 = (PRTL_CRITICAL_SECTION_DEBUG)0x7a5b7b;
      FUN_0089120c();
    } while (piVar8 != (int *)*(int *)(in_ECX + 0x104));
  }
  *(undefined4 *)(in_ECX + 0x110) = 0;
  ExceptionList = (void *)_Stack_24.EntryCount;
  return;
}


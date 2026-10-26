
int * FUN_0079e980(int param_1,undefined4 *param_2,int *param_3)

{
  LPCRITICAL_SECTION p_Var1;
  undefined1 *puVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int *extraout_EAX;
  int iVar7;
  int *extraout_EAX_00;
  int *piVar8;
  PRTL_CRITICAL_SECTION_DEBUG p_Var9;
  PRTL_CRITICAL_SECTION_DEBUG local_58;
  undefined4 local_40;
  int *local_3c;
  undefined1 *local_38;
  int *local_34;
  LPCRITICAL_SECTION local_30;
  LPCRITICAL_SECTION local_2c;
  undefined4 *local_28;
  int *local_24;
  int local_20;
  undefined4 local_1c;
  PRTL_CRITICAL_SECTION_DEBUG local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00938c33;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = *param_2;
  local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79e9c6;
  FUN_00515790();
  if ((local_20 == *(int *)(param_1 + 4)) ||
     (p_Var9 = *(PRTL_CRITICAL_SECTION_DEBUG *)(*(int *)(local_20 + 0x10) + 0x54), local_18 = p_Var9
     , p_Var9 == (PRTL_CRITICAL_SECTION_DEBUG)0x0)) {
    local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79e9e6;
    iVar5 = FUN_00891268();
    local_8._0_1_ = 1;
    if (iVar5 != 0) {
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79e9fa;
      FUN_0079ce90();
    }
    local_58 = (PRTL_CRITICAL_SECTION_DEBUG)&local_38;
    local_8._0_1_ = 0;
    local_38 = (undefined1 *)0x0;
    local_34 = (int *)0x0;
    FUN_007a3400();
    puVar2 = local_38;
    local_8._0_1_ = 2;
    *local_38 = 0;
    FUN_007a0da0();
    piVar8 = local_34;
    *(undefined4 *)(puVar2 + 4) = 0;
    *(undefined4 *)(puVar2 + 0x10) = 0;
    *(undefined4 *)(puVar2 + 0x14) = 0;
    if (param_2[0x1c] == -1) {
      p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x98);
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79ea8e;
      local_2c = p_Var1;
      EnterCriticalSection(p_Var1);
      local_8._0_1_ = 3;
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79eaa1;
      FUN_007a0f60();
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79eaa8;
      LeaveCriticalSection(p_Var1);
      piVar6 = extraout_EAX;
      piVar8 = local_34;
    }
    else {
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
      if ((local_34 != (int *)0x0) && (cVar4 = FUN_0047c250(), cVar4 != '\0')) {
        FUN_007a31c0(puVar2,piVar8);
      }
      FUN_007a90f0(param_2[0x1a]);
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79ea7c;
      piVar6 = (int *)SetEvent((HANDLE)param_2[0x1c]);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (piVar8 == (int *)0x0) goto LAB_0079ecae;
    piVar3 = piVar8 + 1;
    LOCK();
    iVar5 = *piVar3;
    piVar6 = (int *)*piVar3;
    *piVar3 = iVar5 + -1;
    UNLOCK();
    if (iVar5 + -1 != 0) goto LAB_0079ecae;
    piVar6 = (int *)(**(code **)*piVar8)();
    LOCK();
    iVar5 = piVar8[2] + -1;
    piVar8[2] = iVar5;
    UNLOCK();
    if (iVar5 != 0) goto LAB_0079ecae;
    iVar5 = *piVar8;
  }
  else {
    local_58 = (PRTL_CRITICAL_SECTION_DEBUG)&p_Var9[1].CreatorBackTraceIndexHigh;
    if (0xf < p_Var9[2].EntryCount) {
      local_58 = *(PRTL_CRITICAL_SECTION_DEBUG *)local_58;
    }
    FID_conflict__wprintf("(%s)ADDREF: %d\n");
    *(int *)&p_Var9[2].CreatorBackTraceIndexHigh = *(int *)&p_Var9[2].CreatorBackTraceIndexHigh + 1;
    local_58 = (PRTL_CRITICAL_SECTION_DEBUG)(param_2 + 10);
    FUN_0079fbc0(p_Var9);
    piVar8 = *(int **)param_2[0x13];
    if (piVar8 != (int *)param_2[0x13]) {
      do {
        local_58 = p_Var9;
        FUN_007c5b50();
        if (*(char *)((int)piVar8 + 0x11) == '\0') {
          piVar6 = (int *)piVar8[2];
          if (*(char *)((int)piVar6 + 0x11) == '\0') {
            cVar4 = *(char *)(*piVar6 + 0x11);
            piVar8 = piVar6;
            piVar6 = (int *)*piVar6;
            while (cVar4 == '\0') {
              cVar4 = *(char *)(*piVar6 + 0x11);
              piVar8 = piVar6;
              piVar6 = (int *)*piVar6;
            }
          }
          else {
            cVar4 = *(char *)(piVar8[1] + 0x11);
            piVar3 = (int *)piVar8[1];
            piVar6 = piVar8;
            while ((piVar8 = piVar3, cVar4 == '\0' && (piVar6 == (int *)piVar8[2]))) {
              cVar4 = *(char *)(piVar8[1] + 0x11);
              piVar3 = (int *)piVar8[1];
              piVar6 = piVar8;
            }
          }
        }
      } while (piVar8 != (int *)param_2[0x13]);
    }
    local_2c = (LPCRITICAL_SECTION)&local_58;
    local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
    local_24 = param_3;
    local_28 = param_2;
    p_Var1 = (LPCRITICAL_SECTION)&local_58;
    if (param_3 != (int *)0x0) {
      piVar8 = param_3 + 1;
      iVar5 = param_3[1];
      while (p_Var1 = (LPCRITICAL_SECTION)&local_58, iVar5 != 0) {
        LOCK();
        iVar7 = *piVar8;
        if (iVar5 == iVar7) {
          *piVar8 = iVar5 + 1;
          iVar7 = iVar5;
        }
        UNLOCK();
        if (iVar7 == iVar5) {
          FUN_007a31c0(param_2,param_3);
          p_Var9 = local_18;
          p_Var1 = local_2c;
          break;
        }
        p_Var9 = local_18;
        iVar5 = *piVar8;
      }
    }
    local_2c = p_Var1;
    FUN_0079efc0(&local_40,p_Var9);
    piVar8 = local_3c;
    local_8._0_1_ = 4;
    if (param_2[0x1c] == -1) {
      p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x98);
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79ec60;
      local_30 = p_Var1;
      EnterCriticalSection(p_Var1);
      local_8._0_1_ = 5;
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79ec73;
      FUN_007a0f60();
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79ec7a;
      LeaveCriticalSection(p_Var1);
      piVar6 = extraout_EAX_00;
    }
    else {
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
      if ((local_3c != (int *)0x0) && (cVar4 = FUN_0047c250(), cVar4 != '\0')) {
        FUN_007a31c0(local_40,piVar8);
      }
      FUN_007a90f0(param_2[0x1a]);
      local_58 = (PRTL_CRITICAL_SECTION_DEBUG)0x79ec4e;
      piVar6 = (int *)SetEvent((HANDLE)param_2[0x1c]);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_3c == (int *)0x0) goto LAB_0079ecae;
    piVar8 = local_3c + 1;
    LOCK();
    iVar5 = *piVar8;
    piVar6 = (int *)*piVar8;
    *piVar8 = iVar5 + -1;
    UNLOCK();
    if (iVar5 + -1 != 0) goto LAB_0079ecae;
    piVar6 = (int *)(**(code **)*local_3c)();
    LOCK();
    iVar5 = local_3c[2] + -1;
    local_3c[2] = iVar5;
    UNLOCK();
    if (iVar5 != 0) goto LAB_0079ecae;
    iVar5 = *local_3c;
  }
  piVar6 = (int *)(**(code **)(iVar5 + 4))();
LAB_0079ecae:
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    piVar6 = param_3 + 1;
    LOCK();
    iVar5 = *piVar6;
    *piVar6 = iVar5 + -1;
    UNLOCK();
    if (iVar5 + -1 == 0) {
      piVar6 = (int *)(**(code **)*param_3)();
      LOCK();
      iVar5 = param_3[2] + -1;
      param_3[2] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        piVar6 = (int *)(**(code **)(*param_3 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return piVar6;
}


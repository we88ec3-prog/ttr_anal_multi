
void FUN_0080f160(int *param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  undefined4 local_4c;
  char acStack_48 [4];
  uint uStack_44;
  char local_40 [8];
  char acStack_38 [4];
  int aiStack_34 [10];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_4c;
  local_4c = 0xfffffffe;
  if ((in_ECX == 0) || (param_1 == (int *)0x0)) {
    __security_check_cookie(local_c ^ (uint)&local_4c);
    return;
  }
  _memset(param_1,0,0x3c);
  piVar1 = (int *)FUN_00714770();
  param_1[0xd] = (int)piVar1;
  if (piVar1 == (int *)0x0) {
    local_4c = 0xffffffff;
  }
  else {
    (**(code **)(*piVar1 + 0x10))(local_40,1,0xc);
    iVar2 = __strnicmp(local_40,"RIFF",4);
    if ((iVar2 == 0) && (iVar2 = __strnicmp(acStack_38,"WAVE",4), iVar2 == 0)) {
      while (((int *)param_1[0xd] != (int *)0x0 &&
             (iVar2 = (**(code **)(*(int *)param_1[0xd] + 0x10))(acStack_48,1,8), iVar2 == 8))) {
        iVar2 = __strnicmp(acStack_48,"fmt ",4);
        if (iVar2 == 0) {
          piVar1 = (int *)param_1[0xd];
          if (uStack_44 < 0x29) {
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 0x10))(aiStack_34,1,uStack_44);
            }
            if ((short)aiStack_34[0] == 1) {
              param_1[1] = aiStack_34[0];
              param_1[2] = aiStack_34[1];
              param_1[3] = aiStack_34[2];
              *param_1 = 1;
              param_1[4] = aiStack_34[3];
            }
            else if ((short)aiStack_34[0] == -2) {
              *param_1 = 2;
              piVar3 = aiStack_34;
              piVar1 = param_1;
              for (iVar2 = 10; piVar1 = piVar1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
                *piVar1 = *piVar3;
                piVar3 = piVar3 + 1;
              }
            }
          }
          else {
            (**(code **)(*piVar1 + 0x34))(uStack_44,1);
          }
        }
        else {
          iVar2 = __strnicmp(acStack_48,"data",4);
          if (iVar2 == 0) {
            param_1[0xc] = uStack_44;
            iVar2 = (**(code **)(*(int *)param_1[0xd] + 0x30))();
            param_1[0xe] = iVar2;
            (**(code **)(*(int *)param_1[0xd] + 0x34))(uStack_44,1);
          }
          else {
            (**(code **)(*(int *)param_1[0xd] + 0x34))(uStack_44,1);
          }
        }
        if ((uStack_44 & 1) != 0) {
          (**(code **)(*(int *)param_1[0xd] + 0x34))(1,1);
        }
      }
      if (((param_1[0xc] != 0) && (param_1[0xe] != 0)) && ((*param_1 == 1 || (*param_1 == 2)))) {
        local_4c = 0;
        __security_check_cookie(local_c ^ (uint)&local_4c);
        return;
      }
      if ((int *)param_1[0xd] != (int *)0x0) {
        (**(code **)(*(int *)param_1[0xd] + 4))();
        __security_check_cookie(local_c ^ (uint)&local_4c);
        return;
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_4c);
  return;
}


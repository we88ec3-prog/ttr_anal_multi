
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004a39f0(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 *param_4)

{
  char *_Src;
  void *_Dst;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_101c;
  undefined4 local_1014;
  undefined4 local_1010;
  int local_14;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_101c = CONCAT13(param_2,CONCAT12(param_1,0x21));
  iVar2 = 8;
  local_1014 = local_101c;
  local_1010 = param_3;
  local_14 = 8;
  if (param_4 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)*param_4;
    puVar3 = puVar4;
    for (iVar1 = param_4[1] - (int)puVar4 >> 2; iVar1 != 0; iVar1 = iVar1 + -1) {
      _Src = (char *)*puVar3;
      if (*_Src == '\x01') {
        if (iVar2 + 3U < 0x1001) {
          *(undefined2 *)((int)&local_1014 + iVar2) = *(undefined2 *)_Src;
          *(char *)((int)&local_1014 + iVar2 + 2) = _Src[2];
          iVar2 = local_14 + 3;
          local_14 = iVar2;
        }
      }
      else if ((*_Src == '\x02') && (iVar2 + 0x67U < 0x1001)) {
        FID_conflict__memcpy((void *)((int)&local_1014 + iVar2),_Src,0x67);
        iVar2 = local_14 + 0x67;
        local_14 = iVar2;
      }
      puVar3 = puVar3 + 1;
    }
    if (puVar4 != (undefined4 *)param_4[1]) {
      do {
        FUN_0089120c(*puVar4);
        puVar4 = puVar4 + 1;
        iVar2 = local_14;
      } while (puVar4 != (undefined4 *)param_4[1]);
    }
    _Dst = (void *)*param_4;
    if (_Dst != (void *)param_4[1]) {
      FID_conflict__memcpy(_Dst,(void *)param_4[1],0);
      param_4[1] = _Dst;
      iVar2 = local_14;
    }
  }
  (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1014,iVar2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


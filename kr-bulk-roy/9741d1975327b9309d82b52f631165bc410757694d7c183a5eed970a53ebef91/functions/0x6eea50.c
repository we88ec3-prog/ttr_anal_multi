
void FUN_006eea50(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,double param_6)

{
  int iVar1;
  undefined2 *puVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined1 auStack_f4 [35];
  undefined1 local_d1;
  uint local_d0;
  uint local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  char local_c0;
  undefined1 local_bf [2];
  char local_bd [5];
  char local_b8 [116];
  uint local_44;
  
  local_44 = DAT_00d61f20 ^ (uint)auStack_f4;
  uVar4 = *(uint *)(param_4 + 0x18);
  local_c8 = param_1;
  iVar1 = *(int *)(param_4 + 0x1c);
  uVar6 = 0;
  if ((iVar1 < 1) && (((iVar1 < 0 || (uVar4 == 0)) && ((*(uint *)(param_4 + 0x14) & 0x2000) == 0))))
  {
    uVar4 = 6;
    iVar1 = 0;
  }
  local_cc = uVar4;
  if ((-1 < iVar1) && ((0 < iVar1 || (0x24 < uVar4)))) {
    local_cc = 0x24;
  }
  uVar5 = uVar4 - local_cc;
  iVar1 = (iVar1 - ((int)local_cc >> 0x1f)) - (uint)(uVar4 < local_cc);
  uVar4 = *(uint *)(param_4 + 0x14);
  local_d0 = 0;
  if (((uVar4 & 0x3000) == 0x2000) && (param_6 != param_6 * 0.5)) {
    local_d1 = param_6 < 0.0;
    if ((bool)local_d1) {
      param_6 = -param_6;
    }
    if (!NAN(param_6) && 1e+35 < param_6 != (param_6 == 1e+35)) {
      do {
        if (4999 < local_d0) break;
        param_6 = param_6 / 10000000000.0;
        local_d0 = local_d0 + 10;
      } while (1e+35 < param_6 != (param_6 == 1e+35));
    }
    if ((0.0 < param_6) && (-1 < iVar1)) {
      if (0 < iVar1) goto LAB_006eeb6a;
      while (9 < uVar5) {
LAB_006eeb6a:
        do {
          if ((1e-35 < param_6) || (4999 < uVar6)) goto LAB_006eeb95;
          bVar7 = 9 < uVar5;
          uVar5 = uVar5 - 10;
          iVar1 = iVar1 + -1 + (uint)bVar7;
          param_6 = param_6 * 10000000000.0;
          uVar6 = uVar6 + 10;
        } while (0 < iVar1);
        if (iVar1 < 0) break;
      }
    }
LAB_006eeb95:
    if ((bool)local_d1) {
      param_6 = -param_6;
    }
  }
  local_c0 = '%';
  puVar2 = (undefined2 *)local_bf;
  if ((uVar4 & 0x20) != 0) {
    local_bf[0] = 0x2b;
    puVar2 = (undefined2 *)(local_bf + 1);
  }
  if ((uVar4 & 0x10) != 0) {
    *(undefined1 *)puVar2 = 0x23;
    puVar2 = (undefined2 *)((int)puVar2 + 1);
  }
  uVar4 = uVar4 & 0x3000;
  *puVar2 = 0x2a2e;
  if (uVar4 == 0x2000) {
    cVar3 = 'f';
  }
  else if (uVar4 == 0x3000) {
    cVar3 = 'a';
  }
  else {
    cVar3 = (uVar4 != 0x1000) * '\x02' + 'e';
  }
  *(char *)(puVar2 + 1) = cVar3;
  *(undefined1 *)((int)puVar2 + 3) = 0;
  iVar1 = _sprintf_s(local_b8,0x6c,&local_c0,local_cc,param_6);
  FUN_006eeed0(local_c4,local_c8,param_2,param_3,param_4,param_5,local_b8,local_d0,uVar6,uVar5,iVar1
              );
  __security_check_cookie(local_44 ^ (uint)auStack_f4);
  return;
}


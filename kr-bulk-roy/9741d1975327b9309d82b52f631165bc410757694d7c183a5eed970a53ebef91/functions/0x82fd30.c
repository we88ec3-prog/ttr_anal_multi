
void FUN_0082fd30(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *in_ECX;
  int *in_EDX;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar4 = (int)((*in_EDX >> 0x1f & 7U) + *in_EDX) >> 3;
  uVar2 = (int)(in_EDX[1] + (in_EDX[1] >> 0x1f & 7U)) >> 3;
  uVar3 = uVar4 & 0x8000007f;
  bVar5 = uVar3 == 0;
  *in_ECX = 1;
  in_ECX[1] = 1;
  if ((int)uVar3 < 0) {
    bVar5 = (uVar3 - 1 | 0xffffff80) == 0xffffffff;
  }
  if (bVar5) {
    *in_ECX = 0x80;
  }
  uVar3 = uVar2 & 0x8000007f;
  bVar6 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar6 = (uVar3 - 1 | 0xffffff80) == 0xffffffff;
  }
  if (bVar6) {
    in_ECX[1] = 0x80;
  }
  if (!bVar5) {
    uVar3 = uVar4 & 0x8000003f;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xffffffc0) == 0xffffffff;
    }
    if (bVar7) {
      *in_ECX = 0x40;
      bVar5 = true;
    }
  }
  if (!bVar6) {
    uVar3 = uVar2 & 0x8000003f;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xffffffc0) == 0xffffffff;
    }
    if (bVar7) {
      in_ECX[1] = 0x40;
      bVar6 = true;
    }
  }
  if (!bVar5) {
    uVar3 = uVar4 & 0x8000001f;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xffffffe0) == 0xffffffff;
    }
    if (bVar7) {
      *in_ECX = 0x20;
      bVar5 = true;
    }
  }
  if (!bVar6) {
    uVar3 = uVar2 & 0x8000001f;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xffffffe0) == 0xffffffff;
    }
    if (bVar7) {
      in_ECX[1] = 0x20;
      bVar6 = true;
    }
  }
  if (!bVar5) {
    uVar3 = uVar4 & 0x8000000f;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xfffffff0) == 0xffffffff;
    }
    if (bVar7) {
      *in_ECX = 0x10;
      bVar5 = true;
    }
  }
  if (!bVar6) {
    uVar3 = uVar2 & 0x8000000f;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xfffffff0) == 0xffffffff;
    }
    if (bVar7) {
      in_ECX[1] = 0x10;
      bVar6 = true;
    }
  }
  if (!bVar5) {
    uVar3 = uVar4 & 0x80000007;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xfffffff8) == 0xffffffff;
    }
    if (bVar7) {
      *in_ECX = 8;
      bVar5 = true;
    }
  }
  if (!bVar6) {
    uVar3 = uVar2 & 0x80000007;
    bVar7 = uVar3 == 0;
    if ((int)uVar3 < 0) {
      bVar7 = (uVar3 - 1 | 0xfffffff8) == 0xffffffff;
    }
    if (bVar7) {
      in_ECX[1] = 8;
      bVar6 = true;
    }
  }
  if (!bVar5) {
    uVar4 = uVar4 & 0x80000003;
    bVar5 = uVar4 == 0;
    if ((int)uVar4 < 0) {
      bVar5 = (uVar4 - 1 | 0xfffffffc) == 0xffffffff;
    }
    if (bVar5) {
      *in_ECX = 4;
    }
  }
  if (!bVar6) {
    uVar2 = uVar2 & 0x80000003;
    bVar5 = uVar2 == 0;
    if ((int)uVar2 < 0) {
      bVar5 = (uVar2 - 1 | 0xfffffffc) == 0xffffffff;
    }
    if (bVar5) {
      in_ECX[1] = 4;
      __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


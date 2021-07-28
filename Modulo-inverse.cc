// https://cp-algorithms.com/algebra/module-inverse.html
// 1) modular inverse does not always exist
// 2) modular inverse exists if and only if
//    a and m are relatively prime (i.e. gcd(a,m)=1).

// -------------------------------------------------------
// Modulo inverse using Extended Euclidean Algo for 'a' and 'm'
//              ax + my = 1 = gcd(a,m)

// ---------------------------------------------------------
//   modulo inverse using    a^ϕ(m) ≡ 1       mod(m)

// For an arbitrary (but coprime) modulus m: a^(ϕ(m)−1)  ≡ inv(a)modm
// For a prime modulus m: a ^(m−2)  ≡ inv(a)   modm
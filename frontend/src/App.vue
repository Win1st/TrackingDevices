<template>
  <div id="app">
    <!-- nav bar -->
    <nav
      class="navbar navbar-light sticky-top border-bottom bg-dark"
      style="height: 10vh"
    >
      <div class="container-fluid">
        <div class="d-flex">
          <!-- logo -->
          <router-link to="/" :class="center" style="text-decoration: none">
            <div :class="center" class="rounded-pill">
              <img
                :src="require('./assets/image.png')"
                style="max-height: 8vh; width: auto; border-radius: 80%"
              />
              <div class="text-light fw-bold fs-4">TRACKING SYSTEM</div>
            </div>
          </router-link>

          <template v-if="this.$cookies.isKey('account')">
            <router-link
              to="/home"
              :class="center"
              style="text-decoration: none"
            >
              <div
                class="fw-bold text-light fs-4 ms-5 px-3 py-1"
                :class="[center, { 'bg-secondary': hoverHOME }]"
                @mouseover="hoverBooking = true"
                @mouseleave="hoverBooking = false"
                style="border: 3px solid white; border-radius: 10px"
              >
                HOME
              </div>
            </router-link>
            <!-- <router-link
              to="/history"
              :class="center"
              style="text-decoration: none"
            >
              <div
                class="fw-bold text-light fs-4 ms-3 px-3 py-1"
                :class="[center, { 'bg-secondary': hoverCheckIN }]"
                @mouseover="hoverCheckIN = true"
                @mouseleave="hoverCheckIN = false"
                style="border: 3px solid white; border-radius: 10px"
              >
                HISTORY
              </div>
            </router-link> -->
            <router-link
              to="/specification"
              :class="center"
              style="text-decoration: none"
            >
              <div
                class="fw-bold text-light fs-4 ms-3 px-3 py-1"
                :class="[center, { 'bg-secondary': hoverPayment }]"
                @mouseover="hoverPayment = true"
                @mouseleave="hoverPayment = false"
                style="border: 3px solid white; border-radius: 10px"
              >
                SPECIFICATION
              </div>
            </router-link>
          </template>
        </div>
        <template v-if="this.$cookies.isKey('account')">
          <div :class="center">
            <router-link
              to="/profile"
              class="d-flex"
              :class="center"
              style="text-decoration: none"
            >
              <div
                class="bi bi-person text-light"
                style="font-size: 2rem"
              ></div>
              <div class="fw-bold fs-4 mx-2 text-white" :class="center">
                {{ this.$cookies.get("account").username }}
              </div>
            </router-link>
            <button
              type="button"
              class="btn btn-danger btn-sm mx-2 fw-bold fs-4"
              @click.stop="logout()"
            >
              Logout
            </button>
          </div>
        </template>

        <template v-else>
          <div :class="center" class="border-success bg-success rounded-pill">
            <router-link to="/user/login" style="text-decoration: none">
              <div
                class="bi bi-person text-light ms-3"
                style="font-size: 2rem"
              ></div>
            </router-link>
            <router-link to="/user/login" style="text-decoration: none">
              <div class="fw-bold fs-4 text-white mx-2" :class="center">
                Sign In
              </div>
            </router-link>
            <router-link to="/user/login" style="text-decoration: none">
              <div class="fw-bold fs-4 text-white" :class="center">/</div>
            </router-link>
            <router-link to="/user/signup" style="text-decoration: none">
              <div class="fw-bold fs-4 text-white ms-2 me-3" :class="center">
                Sign Up
              </div>
            </router-link>
          </div>
        </template>
      </div>
    </nav>
    <router-view :key="$route.fullPath" />
    <footer class="bg-dark" style="height: 10vh"></footer>
  </div>
</template>

<script>
export default {
  data() {
    return {
      center: {
        "d-flex": true,
        "justify-content-center": true,
        "align-items-center": true,
      },
    };
  },
  methods: {
    logout() {
      this.$cookies.keys().forEach((cookie) => this.$cookies.remove(cookie));
      alert("Logout");
      this.$router.push({ path: "/user/login" });
    },
  },
};
</script>
